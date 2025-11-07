#include <iostream>

bool isInRange(int index) {
    if (index >= 0 && index < 8) {
        return true;
    }
    return false;
}
int main() {
    int possibleMoves[][2] = {{1, 2},  {2, 1},  {-1, 2},  {2, -1},
                              {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
    int tourCount[64] = {};

    for (int tour = 0; tour < 64; tour++) {
        int currentRow = tour / 8;
        int currentColumn = tour % 8;
        int chessBoard[8][8] = {};
        chessBoard[currentRow][currentColumn] = 1;
        std::cout << "Knight started at " << currentRow << ", " << currentColumn
                  << std::endl;
        int countMoves = 0;

        for (int i = 0; i < 8; i++) {
            int tempCurrentRow = currentRow + possibleMoves[i][0];
            int tempCurrentColumn = currentColumn + possibleMoves[i][1];

            if (isInRange(tempCurrentRow) && isInRange(tempCurrentColumn)) {

                if (chessBoard[tempCurrentRow][tempCurrentColumn] != 1) {
                    currentRow = tempCurrentRow;
                    currentColumn = tempCurrentColumn;
                    chessBoard[currentRow][currentColumn] = 1;
                    i = -1;
                    countMoves += 1;
                } else {
                    std::cout << "Already visited this position " << std::endl;
                }
            } else {
                std::cout << "Beyond Bounds " << i << std::endl;
            }
        }
        tourCount[tour] = countMoves;
    }

    for (int i = 0; i < 64; i++) {
        std::cout << i + 1 << "  " << tourCount[i] << std::endl;
    }

    return 0;
}
