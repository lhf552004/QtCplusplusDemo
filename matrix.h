#ifndef MATRIX_H
#define MATRIX_H

#include <vector>



class Matrix
{
private:
    std::vector<std::vector<int>> matrix;
public:
    Matrix(){}
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
};

#endif // MATRIX_H
