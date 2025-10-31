#include <iostream>

int main() {
  int accountNumber = 0;
  float beginBalance;
  float totalItemsCharged;
  float totalCreditsApplied;
  float creditLimit;

  while (accountNumber != -1) {
    std::cout << "Enter account number(or -1 to quit): ";
    std::cin >> accountNumber;
    if (accountNumber != -1) {
      std::cout << "Enter beginning balance: ";
      std::cin >> beginBalance;
      std::cout << "Enter total charges: ";
      std::cin >> totalItemsCharged;
      std::cout << "Enter total credits: ";
      std::cin >> totalCreditsApplied;
      std::cout << "Enter credit limit: ";
      std::cin >> creditLimit;

      float newBalance = beginBalance + totalItemsCharged - totalCreditsApplied;
      std::cout << "New balance is: " << newBalance << std::endl;

      std::cout << "Account: " << accountNumber << std::endl;
      std::cout << "Credit Limit: " << creditLimit << std::endl;
      std::cout << "Balance: " << newBalance << std::endl;

      if (newBalance >= creditLimit) {
        std::cout << "Credit Limit Exceeded" << std::endl;
      }
    }
  }
  return 0;
}
