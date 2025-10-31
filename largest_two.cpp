
#include <iostream>

int main() {
  int counter = 0, number, largest, secondLargest;

  while (counter < 10) {
    std::cout << "Enter your number: ";
    std::cin >> number;
    if (counter == 0) {
      largest = number;
      secondLargest = number;
    }

    if (number > largest) {
      if (largest > secondLargest) {
        secondLargest = largest;
      }
      largest = number;
    } else if (number > secondLargest) {
      secondLargest = number;
    }
    counter++;
  }

  std::cout << "The 2 largest numbers of all typed number are: " << largest
            << ", " << secondLargest << std::endl;
}
