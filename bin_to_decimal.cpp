#include <cmath>
#include <iostream>

int main() {
  int binary;
  std::cout << "Enter a binary number: ";
  std::cin >> binary;

  int flag = 1, number = 0, base = 0, quotient = binary;

  while (flag) {
    int remainder;
    remainder = quotient % 10;
    number += remainder * std::pow(2, base);
    base += 1;
    quotient = quotient / 10;
    if (quotient == 0 || quotient == 1) {
      number += quotient * std::pow(2, base);
      flag = 0;
    }
  }
  std::cout << "Decimal equivalent of " << binary << " is " << number
            << std::endl;
  return 0;
}
