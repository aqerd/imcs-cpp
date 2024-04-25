using namespace std;

class Matrix{
    int N; //размер квадратной матрицы
    double **m; //поле со значениями
    void allocate(int), clear(), check_dimension(const Matrix &);
public:
    Matrix(), Matrix(int), ~Matrix();
    double *operator[](int);
    friend ostream &operator<<(ostream &, const Matrix &);
    Matrix &operator=(const Matrix &);
    Matrix &operator+(const Matrix &);
    Matrix &operator-(const Matrix &);
    Matrix &operator*(double);
    Matrix &operator*(const Matrix &);
};