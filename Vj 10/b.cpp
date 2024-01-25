#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

struct Point {
    double x;
    double y;
   
    Point() : x(0.0), y(0.0) {}

    Point(double x_val, double y_val) : x(x_val), y(y_val) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    // Funkcija za udaljenost od 
    double distanceFromOrigin() const {
        return std::sqrt(x * x + y * y);
    }
};

// Operator >> za unos iz streama
std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}

// Funkcija za ispis 
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
int main() {
    std::ifstream inputFile("points.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1; 
    }

    // read iz zdatoteke
    std::istream_iterator<Point> inputIterator(inputFile);
    std::istream_iterator<Point> endIterator;
    std::vector<Point> points(inputIterator, endIterator);

    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.distanceFromOrigin() < b.distanceFromOrigin();
        });

    double radius = 5.0;
    size_t countInsideCircle = std::count_if(points.begin(), points.end(), [radius](const Point& p) {
        return p.distanceFromOrigin() < radius;
        });

    std::cout << "Number of points inside the circle with radius " << radius << ": " << countInsideCircle << std::endl;


    double replaceDistance = 3.0;
    Point replacementPoint(0.0, 0.0);
    std::replace_if(points.begin(), points.end(), [replaceDistance](const Point& p) {
        return std::abs(p.distanceFromOrigin() - replaceDistance) < 1e-6;
        }, replacementPoint);

    std::cout << "Points in reverse order: ";
    std::reverse_copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
