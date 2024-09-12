#include "matrix.h"


Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result;

    int row = this->matrix.size();
    int rowOther = other.matrix.size();
    int col = this->matrix[0].size();
    int colOther = other.matrix[0].size();
    if(row == 0 || rowOther == 0) {
        return result;
    }
    if(row != rowOther || col!= colOther) {
        return result;
    }

    for(int i = 0; i< row; i++) {
        std::vector<int> newRow;
        for(int j = 0; j< col; j++) {
            newRow.push_back(this->matrix[i][j] + other.matrix[i][j]);
        }
        result.matrix.push_back(newRow);
    }
    return result;
}
