#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int getRollDiceSum() {
    int dice1 = (1 + rand() % 6);
    int dice2 = (1 + rand() % 6);
    return dice1 + dice2;
}

int main() {

    const int numberOfGames = 1000;
    int winRollCounter[100] = {};
    int lostRollCounter[100] = {};
    int gameLength[numberOfGames] = {};

    srand(time(0));

    for (int gameCounter = 0; gameCounter < numberOfGames; gameCounter++) {
        bool gameOver = false;

        while (!gameOver) {
            int roll = 0;
            int sum = getRollDiceSum();

            cout << sum << endl;

            if ((sum == 7 || sum == 11)) {
                cout << "Won the game" << endl;
                winRollCounter[roll]++;
            } else if ((sum == 2 || sum == 3 || sum == 12)) {
                cout << "Lost the game" << endl;
                lostRollCounter[roll]++;
            } else if (sum == 4 || sum == 5 || sum == 6 || sum == 8 ||
                       sum == 9 || sum == 10) {
                bool roundOver = false;
                int point = sum;
                cout << "You made a point. Roll " << point << " again to win."
                     << endl;
                roll++;

                while (!roundOver) {
                    sum = getRollDiceSum();
                    if (sum == 7) {
                        cout << "You rolled a " << sum << endl;
                        cout << "Lost the game" << endl;
                        lostRollCounter[roll]++;
                        roundOver = true;
                    } else if (sum == point) {
                        cout << "You achieved the point " << sum << endl;
                        cout << "Won the game" << endl;
                        winRollCounter[roll]++;
                        roundOver = true;
                    } else {
                        cout << "you rolled " << sum << endl;
                        cout << "Roll again " << endl;
                        roll++;
                    }
                }
            }
            gameLength[gameCounter] = roll;
            gameOver = true;
        }
    }

    // cout << "Winnings after" << setw(50) << "Losings after" << endl;
    // cout << setw(10) << "Rounds" << setw(10) << "Count" << setw(50) <<
    // "Rounds "
    //      << setw(10) << "Count" << endl;
    // for (int i = 0; i < 20; i++) {
    //     cout << setw(10) << i + 1 << setw(10) << winRollCounter[i] <<
    //     setw(50)
    //          << i + 1 << setw(10) << lostRollCounter[i] << endl;
    // }
    for (int i = 0; i < numberOfGames; i++) {
        cout << i + 1 << " game lasted for " << gameLength[i] + 1 << " rounds"
             << endl;
    }
    return 0;
}
