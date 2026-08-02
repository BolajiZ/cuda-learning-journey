#include <iostream>

void reallyChange(int& x) {
    x = 888;
}

int main(){
    int a = 5;
    reallyChange(a);
    std::cout << a << "\n";
    return 0;
}