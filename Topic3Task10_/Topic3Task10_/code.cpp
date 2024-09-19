#include <iostream>

struct Point {
    double x, y;
};

void midpoint(const Point& p1, const Point& p2, Point* result) {
    result->x = (p1.x + p2.x) / 2;
    result->y = (p1.y + p2.y) / 2;
}

double distanceSqr(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    Point vertices[] = { {0, 0}, {5, 0}, {3, 4} };

    int vertex_index;
    std::cout << "Input the index of an apex(1-3) ";
    std::cin >> vertex_index;

    if (vertex_index > 3 || vertex_index <= 0) {
        std::cerr << "Incorrect index of an apex" << std::endl;
        return 1;
    }

    Point a = vertices[vertex_index - 1];
    Point b = vertices[(vertex_index + 2) % 3];
    Point c = vertices[(vertex_index + 1) % 3];
    Point d = vertices[(vertex_index + 3) % 3];

    std::cout << "Median: (" << a.x << ", " << a.y << ") - (" << b.x << ", " << b.y << ")" << std::endl;
    std::cout << "Bissectriss: (" << a.x << ", " << a.y << ") - (" << c.x << ", " << c.y << ")" << std::endl;
    std::cout << "Height: (" << a.x << ", " << a.y << ") - (" << d.x << ", " << d.y << ")" << std::endl;

    return 0;
}