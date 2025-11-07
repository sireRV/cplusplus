#include <iostream>
#include <vector>

struct PossibleJumps {
    int row, col, index, rating;
};

struct PathTaken {
    int row, col;
};

int chessBoard[8][8] = {};
const int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void initialiseChessBoard(const int currentRow, const int currentCol,
                          std::vector<PathTaken> &path) {
    chessBoard[currentRow][currentCol] = 1;
    path.push_back({currentRow, currentCol});
}

bool isInRange(int value) {
    if (value >= 0 && value < 8)
        return true;
    return false;
}

void calculatePossibleJumps(
    const int currentRow, const int currentCol, const int chessBoard[8][8],
    std::vector<PossibleJumps> &possibleJumpsFromCurrentLocation) {

    for (int jumps = 0; jumps < 8; jumps++) {
        int tempCurrentRow = currentRow + vertical[jumps];
        int tempCurrentCol = currentCol + horizontal[jumps];

        if (isInRange(tempCurrentRow) && isInRange(tempCurrentCol) &&
            chessBoard[tempCurrentRow][tempCurrentCol] == 0) {
            possibleJumpsFromCurrentLocation.push_back(
                {tempCurrentRow, tempCurrentCol, jumps});
        }
    }
}

void reduceAccessibilityNumbers(
    int accessibility[8][8],
    std::vector<PossibleJumps> &possibleJumpsFromCurrentLocation) {
    int upperLimit = possibleJumpsFromCurrentLocation.size();

    for (int index = 0; index < upperLimit; index++) {
        int newRating =
            accessibility[possibleJumpsFromCurrentLocation[index].row]
                         [possibleJumpsFromCurrentLocation[index].col]--;
        possibleJumpsFromCurrentLocation[index].rating = newRating;
    }
}

int findBestJumpSlot(
    const std::vector<PossibleJumps> &possibleJumpsFromCurrentLocation) {
    int size = possibleJumpsFromCurrentLocation.size();
    int bestRating = possibleJumpsFromCurrentLocation[0].rating;
    int bestIndex = possibleJumpsFromCurrentLocation[0].index;

    for (int iter = 1; iter < size; iter++) {

        if (possibleJumpsFromCurrentLocation[iter].rating < bestRating) {
            bestRating = possibleJumpsFromCurrentLocation[iter].rating;
            bestIndex = possibleJumpsFromCurrentLocation[iter].index;
        }
    }
    return bestIndex;
}

int main() {

    int currentRow = 0;
    int currentCol = 0;

    int accessibility[8][8] = {
        2, 3, 4, 4, 4, 4, 3, 2, 3, 4, 6, 6, 6, 6, 4, 3, 4, 6, 8, 8, 8, 8,
        6, 4, 4, 6, 8, 8, 8, 8, 6, 4, 4, 6, 8, 8, 8, 8, 6, 4, 4, 6, 8, 8,
        8, 8, 6, 4, 3, 4, 6, 6, 6, 6, 4, 3, 2, 3, 4, 4, 4, 4, 3, 2

    };

    std::vector<PossibleJumps> possibleJumpsFromCurrentLocation;
    std::vector<PathTaken> pathTaken;

    initialiseChessBoard(currentRow, currentCol, pathTaken);

    //    for (int jumps = 0; jumps < 8; jumps++) {

    calculatePossibleJumps(currentRow, currentCol, chessBoard,
                           possibleJumpsFromCurrentLocation);
    reduceAccessibilityNumbers(accessibility, possibleJumpsFromCurrentLocation);

    int bestSlotIndex = findBestJumpSlot(possibleJumpsFromCurrentLocation);

    currentRow = vertical[bestSlotIndex];
    currentCol = horizontal[bestSlotIndex];
    chessBoard[currentRow][currentCol] = 1;
    pathTaken.push_back({currentRow, currentCol});

    //    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << accessibility[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < possibleJumpsFromCurrentLocation.size(); i++) {
        std::cout << possibleJumpsFromCurrentLocation[i].row << "   ";
        std::cout << possibleJumpsFromCurrentLocation[i].col << "   ";
        std::cout << possibleJumpsFromCurrentLocation[i].index << std::endl;
    }

    return 0;
}
