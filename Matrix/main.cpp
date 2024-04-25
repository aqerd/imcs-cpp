//g++ main.cpp matrix.cpp -o prog

#include <iostream>
#include "matrix.h"
using namespace std;

int main(){
    Matrix A(2), B(2), C, addAB, subAB, mulAB, scalarA;
    double scalar = 3.8;

    A[0][0] = 2.5;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = -5;
    
    B[0][0] = 10;
    B[0][1] = 3;
    B[1][0] = -4;
    B[1][1] = 20;

    C = A; 
    cout << "A = " << A << endl;
    addAB = A + B;
    subAB = A - B;
    scalarA = A * scalar;
    mulAB = A * B;
}