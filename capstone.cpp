#include <iostream>


struct DynArray {
    int* data;
    int size;
    int capacity;


};

void push_back(DynArray& arr, int value) {
    if(arr.size == arr.capacity){
        int newCapacity = arr.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < arr.size; i++){
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
        arr.capacity = newCapacity;

    }
    arr.data[arr.size] = value;
    arr.size = arr.size + 1;
}

int main() {
    DynArray arr;
    arr.capacity = 2;
    arr.size = 0;
    arr.data = new int[arr.capacity];

    push_back(arr, 10);
    push_back(arr, 20); // full here we trigger the grow in it
    push_back(arr, 30);
    push_back(arr, 40);

    std::cout << "size: " << arr.size << ", capacity: " << arr.capacity << "\n";
    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " ";
    }
    std::cout << "\n";

    delete[] arr.data;

    return 0;
}