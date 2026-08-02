#include <iostream>

int main() {
    int scores[3] = {90, 85, 70};

    std::cout << "First box: " << scores[0] << "\n";
    
    scores[1] = 100;
    std::cout << "Second box: " << scores[1] << "\n";

    std::cout << "Third box: " << scores[2] << "\n";

    return 0;
}