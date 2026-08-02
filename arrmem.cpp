#include <iostream>

int main(){
    int n = 5;

    int* arr  = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] arr;
    
    return 0;
}