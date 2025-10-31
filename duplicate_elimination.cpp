#include <iostream>
using namespace std;

int main() {
  int numbers[10] = {};
  int counter = 0;
  for (int i = 0; i < 10; i++) {
    int temp;
    bool dirty = false;
    cout << "Enter a number: ";
    cin >> temp;
    if (temp < 10 || temp > 100) {
      cout << "only numbers between 10 and 100 are allowed\n";
      i--;
      continue;
    }
    for (int j = 0; j < i; j++) {
      if (temp == numbers[j]) {
        cout << "Duplicate found" << endl;
        dirty = true;
        break;
      }
    }
    if (!dirty) {
      numbers[counter] = temp;
      counter++;
    }
  }

  for (int i = 0; i < counter; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
  return 0;
}
