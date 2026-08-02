#include <iostream>

struct Point {
    int x;
    int y;
};

void tryToMove(Point& p) {
    p.x = 999;
}

int main() {
    Point p1 = {3, 7};

    tryToMove(p1);

    std::cout << "p1.x is: " << p1.x << "\n";

    return 0;
}

