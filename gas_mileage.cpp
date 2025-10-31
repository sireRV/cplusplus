#include <iostream>

class Mileage {
private:
  double m_milesDriven;
  int m_gallonsUsed;
  double m_totalMilesDriven;
  int m_totalGallonsUsed;

public:
  Mileage();
  void calculate();
};

Mileage::Mileage() {
  m_milesDriven = 0.0;
  m_gallonsUsed = 0;
  m_totalMilesDriven = 0.0;
  m_totalGallonsUsed = 0;
}

void Mileage::calculate() {
  int milesCounter = 0;
  double currentMPG = 0.0;
  while (milesCounter != -1) {
    std::cout << "Enter miles driven(-1 to quit): ";
    std::cin >> m_milesDriven;
    milesCounter = m_milesDriven;
    if (milesCounter != -1) {
      std::cout << "Enter gallons used: ";
      std::cin >> m_gallonsUsed;
      std::cout << m_milesDriven;

      currentMPG = m_milesDriven / m_gallonsUsed;
      std::cout << "MPG this tankful: " << currentMPG << std::endl;

      m_totalMilesDriven += m_milesDriven;
      m_totalGallonsUsed += m_gallonsUsed;

      std::cout << "Total MPG: " << (m_totalMilesDriven / m_totalGallonsUsed)
                << std::endl;
    }
  }
}

int main() {
  Mileage m1;
  m1.calculate();
  return 0;
}
