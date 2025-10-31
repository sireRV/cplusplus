#include <iostream>

int main() {
  int number = 1234, magnitude = 1000;
  int remainder, quotient = number, encrypt = 0;
  int flag = 1;
  while (flag) {
    if (magnitude == 1) {
      flag = 0;
    }
    encrypt += (quotient / magnitude + 7) % 10 * magnitude;
    quotient = quotient % magnitude;
    magnitude = magnitude / 10;
  }

  std::cout << encrypt;
}
