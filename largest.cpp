#include <iostream>

int main() {
  int counter = 0, number, largest;

  while (counter < 10) {
    std::cout << "Enter your number: ";
    std::cin >> number;
    if (counter == 0) {
      largest = number;
    }

    if (number > largest) {
      largest = number;
    }

    counter++;
  }

  std::cout << "The largest number of all typed number is " << largest
            << std::endl;
}
