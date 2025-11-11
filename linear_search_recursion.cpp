#include <iostream>

int linearSearchRecurse(const int arr[], int size, int searchKey) {
    if (size >= 0 && arr[size] == searchKey)
        return size;

    if (size < 0)
        return -1;

    return linearSearchRecurse(arr, size - 1, searchKey);
}
int linearSearch(const int arr[], int size) {
    int searchKey = 1;

    int pos = linearSearchRecurse(arr, size - 1, searchKey);
    return pos;
}
int main() {
    int arr[] = {1, 2, 3};

    int position = linearSearch(arr, 3);

    std::cout << position << "\n";
}
