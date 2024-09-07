#include "matrix_multiplication.h"

#include <iostream>
#include <vector>

// Function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrices(
    const std::vector<std::vector<int>>& matrixA,
    const std::vector<std::vector<int>>& matrixB) {

    // Check if multiplication is possible
    if (matrixA.empty() || matrixB.empty() || matrixA[0].size() != matrixB.size()) {
        throw std::invalid_argument("Invalid matrix dimensions for multiplication");
    }

    // Get dimensions of the result matrix
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    // Initialize the result matrix with zeros
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}
