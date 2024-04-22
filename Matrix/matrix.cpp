#include "matrix.h"

void Matrix::allocate(int n){
    m = new double*[n];
    for (int i = 0; i < n; i++){
        m[i] = new double[n];
    }
}

void Matrix::clear(){
    for (int i = 0; i < N; i++)
        delete[] m[i];
    if (N > 0)
        delete[] m;
}

Matrix::Matrix(){
    N = 0;
    m = nullptr;
}

Matrix::Matrix(int n){
    N = n;
    allocate(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            m[i][j] = 0;
    }
}

Matrix::~Matrix(){
    clear();
}