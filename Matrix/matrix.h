class Matrix{
    int N; //размер квадратной матрицы
    double **m; //поле со значениями
    void allocate(int), clear();
public:
    Matrix(), Matrix(int), ~Matrix();
};