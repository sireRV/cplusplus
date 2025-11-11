#include <iomanip>
#include <iostream>

int main() {
    int array[5] = {5, 2, 8, 1, 3};

    for (int i = 0; i < 5; i++) {
        int smallest = array[i];
        int temp = 0;
        int index = -1;
        for (int j = i + 1; j < 5; j++) {
            if (array[j] < smallest) {
                smallest = array[j];
                index = j;
            }
        }
        if (index != -1) {
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
            index = -1;
        }
    }

    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << "   ";
    }
    std::cout << "\n";

    return 0;
}
