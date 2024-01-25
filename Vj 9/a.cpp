#include <iostream>
#include <string>

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int intResult = minimum(5, 10);
    double doubleResult = minimum(3.14, 2.71);

    std::string str1 = "hello";
    std::string str2 = "world";
    std::string strResult = minimum(str1, str2);

    std::cout << "Min of 5 and 10: " << intResult << std::endl;
    std::cout << "Min of 3.14 and 2.71: " << doubleResult << std::endl;
    std::cout << "Min of 'hello' and 'world': " << strResult << std::endl;

    return 0;
}
