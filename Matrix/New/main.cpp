#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "matrix.h"
using namespace std;
const string InputFileName = "source.txt";
const string OutputFileName = "output.txt";

/*В файле записана информация о квадратных матрицах: количество матриц и о каждой количество элементов. 
Выбрать и выписать в новый файл симметричные матрицы, упорядочив их по убыванию следа. 
Также необходимо записать в этот файл след матриц. Реализовать многофайловый проект.*/

int main() {
    // Проверка методов
    /*Matrix A(2);
    Matrix B(2);

    A[0][0] = 2.5;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = -5;
    B[0][0] = 10;
    B[0][1] = 3;
    B[1][0] = -4;
    B[1][1] = 20;

    Matrix C = A + B;
    cout << "Matrix C:" << endl;
    cout << C << endl;
    double s = 3.3;
    C = C - B;
    cout << "Matrix C:" << endl;
    cout << C << endl;
    cout << "Matrix A:" << endl;
    cout << A << endl;
    cout << "Matrix B:" << endl;
    cout << B << endl;
    Matrix T = C.transpose();
    cout << T << endl;*/

    // Проверка на существование файла
    fstream InputFile(InputFileName);
    if (!InputFile.is_open()) {
        cout << "ERROR: Unable to open source Input file" << endl;
        exit(1);
    }

    double m;
    int number_of_matrices, n;
    string line, useless;
    vector<Matrix> matrices;

    // Чтение первой строки (количества матриц)
    getline(InputFile, line);
    istringstream iss(line);
    iss >> useless >> useless >> useless >> useless >> number_of_matrices;

    // Запись значений в матрицу
    while (getline(InputFile, line)) {
        if (get_size(line) > 0) {
            n = get_size(line);
        }

        Matrix A(n);
        for (int i = 0; i < n; i++) {
            getline(InputFile, line);
            istringstream iss(line);
            for (int j = 0; j < n; j++) {
                iss >> m;
                A[i][j] = m;
            }
        }

        if (A.symmetry()) {
            matrices.push_back(A);
        }
    }
    cout << "Matrices pushed to vector successfully" << endl;

    SortByTrace(matrices);
    cout << "Vector of matrices sorted successfully" << endl;

    // вывод в терминал
    /*cout << "Sorted matrices by trace:" << endl;
    for (const Matrix& A : matrices) {
        cout << "Trace: " << A.trace() << endl;
        cout << A << endl;
    }*/

    InputFile.close();

    ofstream OutputFile(OutputFileName);
    if (!OutputFile.is_open()) {
        cout << "ERROR: Unable to open output Input file" << endl;
        return 1;
    }

    // Запись в файл
    OutputFile << "Number of sorted matrices by trace = " << matrices.size() << endl;
    for (const Matrix& A : matrices) {
        OutputFile << "n = " << A.size() << ", Trace: " << A.trace() << endl;
        OutputFile << A << endl;
    }
    cout << "Matrices written into output Input file successfully" << endl;

    OutputFile.close();
    system("pause");
    return 0;
}