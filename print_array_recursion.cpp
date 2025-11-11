#include <iostream>

void print_array(const int arr[], int start, int end) {
    if (start <= end) {
        std::cout << arr[start] << "    ";
    } else {
        return;
    }
    print_array(arr, start + 1, end);
}

void reverse_string(const std::string str, int start) {
    if (str.length() == start) {
        return;
    }
    std::cout << str[str.length() - start - 1];

    reverse_string(str, start + 1);
}
int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string mystr = "My Name is Anthony Gonsalves";
    print_array(array, 0, 9);
    std::cout << "\n\n" << mystr.length() << "\n\n";
    reverse_string(mystr, 0);
    return 0;
}
