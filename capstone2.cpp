#include <iostream>

struct Matrix {
    int* data;
    int rows;
    int cols;
};

int main(){
    Matrix m;
    m.rows = 2;
    m.cols = 3;
    m.data = new int[m.rows * m.cols];

    // fill 1..6
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = i + 1;
    }

    int row = 1, col = 2;
    int index = row * m.cols + col;
    std::cout << "(" << row << "," << col << ") = " << m.data[index] << "\n";


    delete[] m.data;

    return 0;
}






