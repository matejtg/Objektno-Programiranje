#include <iostream>
#include <algorithm>

template <typename T>
void sortArray(T arr[], size_t size) {
    std::sort(arr, arr + size);
}

template <>
void sortArray<char>(char arr[], size_t size) {
    std::sort(arr, arr + size, [](char a, char b) {
        return std::tolower(a) < std::tolower(b);
        });
}

int main() {
    int intArray[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    size_t intSize = sizeof(intArray) / sizeof(int);
    std::cout << "Original int array: ";
    for (size_t i = 0; i < intSize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    sortArray(intArray, intSize);

    std::cout << "Sorted int array: ";
    for (size_t i = 0; i < intSize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    char charArray[] = { 'b', 'C', 'a', 'D' };
    size_t charSize = sizeof(charArray) / sizeof(char);
    std::cout << "\nOriginal char array: ";
    for (size_t i = 0; i < charSize; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    sortArray(charArray, charSize);

    std::cout << "Sorted char array (case-insensitive): ";
    for (size_t i = 0; i < charSize; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
