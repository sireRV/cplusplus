#include <iostream>

int getMinimumPosition(const int arr[], int size, int index) {
    if (index == size - 1) {
        return index;
    }

    int minPos = getMinimumPosition(arr, size, index + 1);
    if (arr[minPos] < arr[index])
        return minPos;
    else
        return index;
}

int selectionSort(int arr[], int size, int index) {
    if (size - index == 1) {
        return arr[index];
    }

    int minimum = getMinimumPosition(arr, size, index);

    if (minimum != index) {
        int temp = arr[index];
        arr[index] = arr[minimum];
        arr[minimum] = temp;
    }
    return selectionSort(arr, size, index + 1);
}

int main() {
    int array[5] = {55, 32, 103, 11, 25};

    selectionSort(array, 5, 0);

    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << "    ";
    }
}
