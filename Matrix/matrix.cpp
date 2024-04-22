#include <iostream>
#include "matrix.h"
using namespace std;

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

void Matrix::check_dimension(const Matrix & T){
    if (N != T.N){
        cout << "Error: matrixes have different dimensions" << endl;
        exit(1);
    }
}

double* Matrix::operator[](int idx){
    return m[idx];
}
/*
ostream operator<<(ostream &os, const Matrix &obj){
    os << endl;
    for (int i = 0; i < obj.N; i++){
        for (int j = 0; j < obj.N; j++){
            os << obj.m[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}*/

Matrix& Matrix::operator=(const Matrix & A){
    if (N != A.N){
        clear();
        N = A.N;
        allocate(N);
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            m[i][j] = A.m[i][j];
    }
    return *this;
}

Matrix& Matrix::operator+(const Matrix & T){
    check_dimension(T);
    Matrix* P = new Matrix(N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *P[i][j] = m[i][j] + T.m[i][j];
        }
    }
    return *P;
}

Matrix& Matrix::operator-(const Matrix & T){
    check_dimension(T);
    Matrix* P = new Matrix(N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *P[i][j] = m[i][j] - T.m[i][j];
        }
    }
    return *P;
}

Matrix& Matrix::operator*(double phi){
    Matrix* P = new Matrix(N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *P[i][j] = m[i][j] * phi;
        }
    }
    return *P;
}

//Matrix& Matrix::operator*(const Matrix & A){}

Matrix::~Matrix(){
    clear();
}