#include <iostream>

int main() {
    int total = 0;
    for (int i = 1; i <= 5; i++) {
        total = total + i;
        std::cout << "i=" << i << "  total is now " << total << "\n";
    }
    std::cout << "final total = " << total << "\n";
    return 0;
}
