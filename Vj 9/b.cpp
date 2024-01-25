#include <iostream>
#include <unordered_set>

template <typename T>
class Set {
private:
    std::unordered_set<T> elements;

public:
    void add(const T& element) {
        elements.insert(element);
    }

    void remove(const T& element) {
        elements.erase(element);
    }

    bool contains(const T& element) const {
        return (elements.find(element) != elements.end());
    }

    void print() const {
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);

    std::cout << "Elements in the integer set: ";
    intSet.print();

    intSet.remove(2);

    std::cout << "After removing 2, elements in the integer set: ";
    intSet.print();

    std::cout << "Is 3 in the integer set? " << (intSet.contains(3) ? "Yes" : "No") << std::endl;
    std::cout << "Is 5 in the integer set? " << (intSet.contains(5) ? "Yes" : "No") << std::endl;

    Set<std::string> stringSet;
    stringSet.add("apple");
    stringSet.add("orange");
    stringSet.add("banana");

    std::cout << "\nElements in the string set: ";
    stringSet.print();

    return 0;
}
