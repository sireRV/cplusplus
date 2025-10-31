#include <iostream>

using namespace std;

int main() {
  // int array[10] = {32, 12, 35, 56, 2, 1, 20, 15, 11, 5};
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int j = 0; j < 10; j++) {
    bool swapped = false;
    cout << j + 1 << " Iteration" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < 9 - j; i++) {
      cout << "Successive Elements: " << array[i] << " " << array[i + 1]
           << endl;
      cout << "Comparing " << array[i] << " and " << array[i + 1] << endl;
      if (array[i] > array[i + 1]) {
        swapped = true;
        cout << "swapping " << array[i] << " and " << array[i + 1] << endl;
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
    if (!swapped) {
      break;
    }
    for (int i = 0; i < 10; i++) {
      cout << array[i] << " ";
    }
    cout << "\n----------------------" << endl;
  }

  cout << endl;
  return 0;
}
