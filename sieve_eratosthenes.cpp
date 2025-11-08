#include <iostream>

int main() {

    int array[1000];

    for (int index = 0; index < 1000; index++) {
        array[index] = 1;
    }

    for (int index = 2; index < 1000; index++) {
        if (array[index] != 0) {

            for (int sub = index + 1; sub < 1000; sub++) {
                if (array[sub] == 0) {
                    continue;
                }
                if (sub % index == 0) {
                    array[sub] = 0;
                }
            }
        }
    }

    for (int i = 2; i < 1000; i++) {
        if (array[i] != 0) {
            std::cout << i << "   ";
            if (i % 10 == 0)
                std::cout << "\n";
        }
    }
    std::cout << "\n";
    return 0;
}
