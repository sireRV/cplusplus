#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int rollDice() { return (1 + rand() % 6); }

int main() {
    const int arraySize = 49;
    int diceTotalCount[arraySize] =
        {}; // storing sum of separate combinations. 1 and 2, 2 and 1
    // stored separately
    int diceSumCount[13] =
        {}; // sum of dice rolls. sum of 3(1 and 2, 2 and 1 throw stored in same
    // index)
    const int numberOfTries = 36000;
    srand(time(0));

    for (int i = 0; i < numberOfTries; i++) {
        int dice1 = rollDice();
        int dice2 = rollDice();
        int sum = dice1 + dice2;
        diceTotalCount[dice1 * arraySize / 7 + dice2]++;
        diceSumCount[sum]++;
    }

    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            cout << setw(6) << diceTotalCount[i * 7 + j] << "    ";
        }
        cout << endl;
    }

    for (int i = 2; i < 13; i++) {
        float probability;
        probability = float(diceSumCount[i]) * 100 / numberOfTries;
        cout << setw(4) << i << setw(6) << diceSumCount[i] << setw(12)
             << probability << endl;
    }
    cout << endl;
    return 0;
}
