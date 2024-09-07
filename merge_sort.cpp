#include "merge_sort.h"

#include <iostream>
#include <vector>

// Function to merge two sorted subarrays into a single sorted array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Calculate the sizes of the two subarrays to be merged
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary subarrays
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // Copy data to temporary subarrays
    for (int i = 0; i < n1; ++i) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = arr[mid + 1 + j];
    }

    // Merge the temporary subarrays back into the original array
    int i = 0;     // Initial index of the left subarray
    int j = 0;     // Initial index of the right subarray
    int k = left;  // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of the left subarray, if any
    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of the right subarray, if any
    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort on the array
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the midpoint

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to initiate merge sort
void mergeSort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}
