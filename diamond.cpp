
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Diamond {
  int width;

public:
  Diamond() { width = 0; }

  void getWidth() {
    cout << "how wide the diamond should be: ";
    cin >> width;
  }

  void display() {
    int mid = width / 2;
    for (int i = 0; i < width; i++) {
      int stars = width - (2 * abs(mid - i));
      int spaces = (width - stars) / 2;
      for (int j = 0; j < spaces; j++) {
        cout << " ";
      }
      for (int k = 0; k < stars; k++) {
        if (k == 0 || k == stars - 1) {

          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
};

int main() {
  Diamond d1;
  d1.getWidth();
  d1.display();
  return 0;
}
