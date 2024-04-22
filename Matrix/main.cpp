//g++ main.cpp matrix.cpp -o prog

#include <iostream>
#include "matrix.h"
using namespace std;

int main(){
    Matrix A(2), B(2), C;
    A[0][0] = 2.5;
    A[0][1] = A[1][0] = 1;
    A[1][1] = -5;
    //cout << "A = " << A << endl;
    C = A;
    B[0][0] = 10;
    B[0][1] = 3;
    B[1][0] = -4;
    B[1][1] = 20;
    double phi = 3.8;
    C = A + B;
    C = A - B;
    C = A * phi;
    //C = A * B;
}