#include <iostream>

struct Point {

    int x;
    int y;
};

int main() {
    Point p1 = {3, 7};
    
    Point p2 = {10, 20};

    std::cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")\n";

    return 0;
}