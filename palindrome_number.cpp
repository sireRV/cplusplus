#include <iostream>

int main() {
  int number, reversedNumber = 0;
  int flag = 1;
  std::cout << "Enter a number:";
  std::cin >> number;

  int quotient = number;
  while (flag) {
    int remainder;
    remainder = quotient % 10;
    quotient = quotient / 10;
    reversedNumber += remainder;
    reversedNumber *= 10;
    if (quotient >= 0 && quotient <= 9) {
      flag = 0;
      reversedNumber += quotient;
    }
  }
  std::cout << reversedNumber << std::endl;
  if (number == reversedNumber) {
    std::cout << "We have a palindrome here: " << std::endl;
  }
  return 0;
}
