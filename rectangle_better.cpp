
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Rectangle {
  unsigned int length;

public:
  Rectangle() { length = 0; }

  void getLength() { cin >> length; }

  void display() {
    for (int i = 0; i < length; i++) {
      if (i == 0 || i == length - 1) {
        for (int j = 0; j < length; j++) {
          cout << "*";
        }
      } else {
        cout << "*";
        for (int j = 1; j < length - 1; j++) {
          cout << " ";
        }
        cout << "*";
      }
      cout << endl;
    }
  }
};

int main() {
  Rectangle r1;
  r1.getLength();
  r1.display();
}
