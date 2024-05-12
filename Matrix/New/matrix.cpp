#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int size) {
    N = size;

    if (N <= 0) {
        cout << "ERROR: Matrix size must be positive" << endl;
        exit(1);
    }

    m = new double*[N];
    for (int i = 0; i < N; ++i) {
        m[i] = new double[N];
        for (int j = 0; j < N; ++j) {
            m[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < N; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

Matrix::Matrix(const Matrix &T) {
    N = T.N;

    m = new double*[N];
    for (int i = 0; i < N; ++i) {
        m[i] = new double[N];
        for (int j = 0; j < N; ++j) {
            m[i][j] = T.m[i][j];
        }
    }
}

void Matrix::clear() {
    for (int i = 0; i < N; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

int Matrix::size() const {
    return N;
}

void Matrix::check_dimension(const Matrix &T) {
    if (N != T.N) {
        cout << "ERROR: Matrices have different sizes" << endl;
        exit(1);
    }
}

bool Matrix::symmetry() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (m[i][j] != m[j][i]) {
                return false;
            }   
        }      
    }
    return true;
}

Matrix Matrix::transpose() {
    Matrix T(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T[i][j] = m[j][i];
        }
    }
    return T;
}

double Matrix::trace() const {
    double trace = 0.0;
    for (int i = 0; i < N; ++i) {
        trace += m[i][i];
    }
    return trace;
}

bool Matrix::compare_trace(const Matrix &A, const Matrix &B) {
    return A.trace() > B.trace();
}

Matrix &Matrix::operator=(const Matrix &T) {
    if (this != &T) {
        clear();
        N = T.N;

        m = new double*[N];
        for (int i = 0; i < N; ++i) {
            m[i] = new double[N];
            for (int j = 0; j < N; ++j) {
                m[i][j] = T.m[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &T) {
    check_dimension(T);
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.m[i][j] = m[i][j] + T.m[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &T) {
    check_dimension(T);
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.m[i][j] = m[i][j] - T.m[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &T) {
    check_dimension(T);
    Matrix result(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result.m[i][j] += m[i][k] - T.m[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) {
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}

double* Matrix::operator[](int index) {
    if (index < 0 || index >= N) {
        cout << "ERROR: Index out of range" << endl;
        exit(1);
    }
    return m[index];
}

ostream& operator<<(ostream &os, const Matrix &T) {
    for (int i = 0; i < T.N; ++i) {
        for (int j = 0; j < T.N; ++j) {
            os << right << setw(4) << setfill(' ') << T.m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int get_size(string line) {
    string key, useless;
    int n;
    istringstream iss(line);
    iss >> key >> useless >> n;
    if (key == "n") {
        return n;
    } else {
        return 0;
    }
}

void SortByTrace(vector<Matrix> &matrices) {
    for (size_t i = 0; i < matrices.size() - 1; ++i) {
        for (size_t j = i + 1; j < matrices.size(); ++j) {
            if (matrices[j].trace() > matrices[i].trace()) {
                swap(matrices[i], matrices[j]);
            }
        }
    }
}