#include <iostream>

struct DynArray {
    int* data;
    int size;
    int capacity;
};

void push_back(DynArray& arr, int value) {
    arr.data[arr.size] = value;
    arr.size = arr.size + 1;
}

int main() {
    DynArray arr;
    arr.capacity = 2;
    arr.size = 0;
    arr.data = new int[arr.capacity];


    push_back(arr, 10);
    push_back(arr, 20);

    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " ";
    }

    std::cout << "\n";

    delete[] arr.data;
    return 0;
    
}