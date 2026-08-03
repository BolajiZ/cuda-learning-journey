#include <iostream>

struct Matrix {
    int* data;
    int rows;
    int cols;
    
};


// Read the value at (row, col)
int get(Matrix& m, int row, int col) {
    int index = row * m.cols + col;
    return m.data[index];
}

// write value at (row, col)
void set(Matrix& m, int row, int col, int value) {
    int index = row * m.cols + col;
    m.data[index] = value;
}

int main() {
    Matrix m;
    m.rows = 2;
    m.cols = 3;
    m.data = new int[m.rows * m.cols];

    set(m, 0, 0, 1);   set(m, 0, 1, 2);   set(m, 0, 2, 3);
    set(m, 1, 0, 4);   set(m, 1, 1, 5);   set(m, 1, 2, 6);
    
    // read out a few values using get()
    std::cout << "(0,1) = " << get(m, 0, 1) << "\n";
    std::cout << "(1,2) = " << get(m, 1, 2) << "\n";

    delete[] m.data;
    return 0;
}





