#include <iomanip>
#include <iostream>

const int SIZE = 8;
int chessBoard[SIZE][SIZE] = {};

void invalidateColumn(int row, int column) {
    if (column == 8)
        return;
    chessBoard[row][column] = -1;
    invalidateColumn(row, column + 1);
}

void invalidateRow(int row, int column) {
    if (row == 8)
        return;
    chessBoard[row][column] = -1;
    invalidateRow(row + 1, column);
    invalidateRow(row + 1, column + 1);
}

// void invalidateDiagonal(int row, int column) {
//     if (row == 8)
//         return;
//     chessBoard[row][column] = -1;
//     invalidateDiagonal(row + 1, column + 1);
// }

void eightQueenRecurse(int num, int row, int col) {
    if (num == 0) {
        return;
    }
    std::cout << "Recursion " << num << std::endl;
    for (int i = 0; i < SIZE; i++) {
        if (chessBoard[row][i] != -1 && chessBoard[row][i] == 0) {
            chessBoard[row][i] = 2;
            invalidateRow(row + 1, i);
            invalidateColumn(row, i + 1);
            invalidateRow(row + 1, i + 1);
        }
    }
    eightQueenRecurse(num - 1, row + 1, col);
}

int main() {
    int numberOfQueens = 8;

    eightQueenRecurse(numberOfQueens, 0, 0);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << std::setw(5) << chessBoard[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}
