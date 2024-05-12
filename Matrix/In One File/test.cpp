#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const string InputFileName = "source.txt";
const string OutputFileName = "output.txt";

/*В файле записана информация о квадратных матрицах: количество матриц и о каждой количество элементов. 
Выбрать и выписать в новый файл симметричные матрицы, упорядочив их по убыванию следа. 
Также необходимо записать в этот файл след матриц. Реализовать многофайловый проект.*/

class Matrix {
    int N;
    double **m;

public:
    Matrix(int size) {
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

    ~Matrix() {
        for (int i = 0; i < N; ++i) {
            delete[] m[i];
        }
        delete[] m;
    }

    Matrix(const Matrix &T) {
        N = T.N;

        m = new double*[N];
        for (int i = 0; i < N; ++i) {
            m[i] = new double[N];
            for (int j = 0; j < N; ++j) {
                m[i][j] = T.m[i][j];
            }
        }
    }

    void clear() {
        for (int i = 0; i < N; ++i) {
            delete[] m[i];
        }
        delete[] m;
    }

    int size() const {
        return N;
    }

    void check_dimension(const Matrix &T) {
        if (N != T.N) {
            cout << "ERROR: Matrices have different sizes" << endl;
            exit(1);
        }
    }

    bool symmetry() {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (m[i][j] != m[j][i]) {
                    return false;
                }   
            }      
        }
        return true;
    }

    Matrix transpose() {
        Matrix T(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                T[i][j] = m[j][i];
            }
        }
        return T;
    }

    double trace() const {
        double trace = 0.0;
        for (int i = 0; i < N; ++i) {
            trace += m[i][i];
        }
        return trace;
    }

    static bool compare_trace(const Matrix &A, const Matrix &B) {
        return A.trace() > B.trace();
    }

    Matrix &operator=(const Matrix &T) {
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

    Matrix operator+(const Matrix &T) {
        check_dimension(T);
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result.m[i][j] = m[i][j] + T.m[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &T) {
        check_dimension(T);
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result.m[i][j] = m[i][j] - T.m[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &T) {
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

    Matrix operator*(double scalar) {
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result.m[i][j] = m[i][j] * scalar;
            }
        }
        return result;
    }

    double* operator[](int index) {
        if (index < 0 || index >= N) {
            cout << "ERROR: Index out of range" << endl;
            exit(1);
        }
        return m[index];
    }

    friend ostream &operator<<(ostream &os, const Matrix &T) {
        for (int i = 0; i < T.N; ++i) {
            for (int j = 0; j < T.N; ++j) {
                os << T.m[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

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
        cout << "ERROR: Unable to open source InputFile" << endl;
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
        cout << "ERROR: Unable to open output InputFile" << endl;
        return 1;
    }

    // Запись в файл
    OutputFile << "Number of sorted matrices by trace = " << matrices.size() << endl;
    for (const Matrix& A : matrices) {
        OutputFile << "n = " << A.size() << ", Trace: " << A.trace() << endl;
        OutputFile << A << endl;
    }
    cout << "Matrices written to output InputFile successfully" << endl;

    OutputFile.close();
    return 0;
}