#include <iostream>

using namespace std;

int main() {
  int salary[] = {1500, 900, 850, 670, 230, 460, 570, 390};
  int counter[9] = {};

  for (int i = 0; i < 8; i++) {
    cout << salary[i] << " ";
    if (salary[i] >= 1000)
      counter[8]++;
    else
      counter[salary[i] / 100 - 2]++;
  }
  cout << endl;

  for (int i = 0; i < 9; i++) {
    int minRange = (i + 2) * 100;
    int maxRange = minRange + 99;
    if (maxRange <= 999)
      cout << "$" << minRange << "-" << maxRange << ": " << counter[i] << endl;
    else
      cout << "$" << minRange << " and over" << ": " << counter[i] << endl;
  }
  return 0;
}
