#include <iomanip>
#include <iostream>

const int SIZE = 8;
int chessBoard[SIZE][SIZE] = {};

int findSlotOnBoard(const int chessBoard[SIZE][SIZE]) {
    int bestSlot = -2;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (chessBoard[row][col] != -1 && chessBoard[row][col] != 2) {
                bestSlot = row * SIZE + col;
                return bestSlot;
            }
        }
    }
    return bestSlot;
}

void placeQueenOnBoard(int slot, int chessBoard[SIZE][SIZE]) {
    int row = slot / SIZE;
    int col = slot % SIZE;
    std::cout << "Placing Queen at (" << row << "," << col << ")" << std::endl;
    chessBoard[row][col] = 2;

    for (int index = col + 1; index < SIZE; index++) {
        chessBoard[row][index] = -1;
    }

    for (int index = row + 1; index < SIZE; index++) {
        chessBoard[index][col] = -1;
    }

    for (int index = row + 1; index < SIZE - row - col; index++) {
        // for(int horizontal=col+1;horizontal<SIZE;horizontal++) {
        chessBoard[row + index][col + index] = -1;
        //}
    }
}

int main() {
    int numberOfQueens = SIZE;

    while (numberOfQueens > 0) {
        int slot = findSlotOnBoard(chessBoard);
        if (slot != -2) {
            placeQueenOnBoard(slot, chessBoard);
        }
        numberOfQueens--;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << std::setw(5) << chessBoard[i][j];
        }
    std:
        std::cout << "\n";
    }
    return 0;
}
