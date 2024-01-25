#include <iostream>
#include <cmath>

template <typename T>
class point {
private:
    T x;
    T y;

public:
    point(T x_val, T y_val) : x(x_val), y(y_val) {}

    double operator-(const point& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    point<int> p1(2, 3);
    point<int> p2(3, 4);

    std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << std::endl;

    return 0;
}
