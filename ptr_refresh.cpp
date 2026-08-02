#include <iostream>

int main() {
    int score = 50;
    int* ptr = &score;

    std::cout << "value:   " << score << "\n";    // predict?
    std::cout << "address: " << &score << "\n";   // predict?
    std::cout << "ptr:     " << ptr << "\n";      // predict?
    std::cout << "*ptr:    " << *ptr << "\n";     // predict?

    return 0;
}