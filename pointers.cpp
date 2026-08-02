#include <iostream>

int main(){

    int x = 10;
    int* p = &x;
    *p = 55;
    std::cout << x << "\n";

    return 0;
}