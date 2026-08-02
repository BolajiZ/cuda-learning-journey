#include <iostream>

    struct Rectangle {
        int width = 5;
        int height = 3;
    };
int main(){
    Rectangle rect = {5, 3};

    int area = rect.width * rect.height;

    std::cout << "Area: " << area << "\n";



    return 0;
}