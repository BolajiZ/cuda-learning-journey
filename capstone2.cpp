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

void print(Matrix&m) {
    for (int row = 0; row < m.rows; row++) {
        for (int col = 0; col < m.cols; col++) {
            std::cout << get(m, row, col) << " ";

        }
        std::cout << "\n";
    }
}

int main() {
    Matrix m;
    m.rows = 2;
    m.cols = 3;
    m.data = new int[m.rows * m.cols];

    set(m, 0, 0, 1);   set(m, 0, 1, 2);   set(m, 0, 2, 3);
    set(m, 1, 0, 4);   set(m, 1, 1, 5);   set(m, 1, 2, 6);
    
    print(m);

    delete[] m.data;
    return 0;
}





