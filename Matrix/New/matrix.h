#include <iostream>
using namespace std;

class Matrix {
    int N;
    double **m;
public:
    Matrix(int size);
    ~Matrix();
    Matrix(const Matrix &T);
    void clear();
    int size() const;
    void check_dimension(const Matrix &T);
    bool symmetry();
    Matrix transpose();
    double trace() const;
    bool compare_trace(const Matrix &A, const Matrix &B);
    Matrix &operator=(const Matrix &T);
    Matrix operator+(const Matrix &T);
    Matrix operator-(const Matrix &T);
    Matrix operator*(const Matrix &T);
    Matrix operator*(double scalar);
    double* operator[](int index);
    friend ostream& operator<<(ostream &os, const Matrix &T);
};
int get_size(string line);
void SortByTrace(vector<Matrix> &matrices);