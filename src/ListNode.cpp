#include "ListNode.h"
#include <iostream>

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;    // Initialize previous pointer to null
    ListNode* current = head;    // Start with the current node as the head
    ListNode* next = nullptr;    // This will store the next node temporarily

    while (current != nullptr) { // Traverse until the end of the list
        next = current->next;    // Save the next node
        current->next = prev;    // Reverse the link
        prev = current;          // Move the 'prev' pointer to the current node
        current = next;          // Move the 'current' pointer to the next node
    }

    return prev; // 'prev' is the new head of the reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
