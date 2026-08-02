#include <iostream>

int main() {
     int squares[5];

     for (int i = 0; i < 5; i++) {
        squares[i] = i * i;
     }
     
     int total = 0;
     for (int i = 0; i < 5; i++) {
         total = total + squares[i];

     }
     
std::cout << "Sum of all boxes: " << total << "\n";

    return 0;
}