#include <iostream>
#include <cmath>
#include <complex>
const int N = 100;
using namespace std;

class Complex {
public:
    double Re, Im;

    Complex() {
        this->Re = 0;
        this->Im = 0;
    }

    Complex(double Re, double Im) {
        this->Re = Re;
        this->Im = Im;
    }

    Complex operator=(double x){
        Re = x;
        Im = 0;
        return *this;
    }

    Complex operator*(Complex obj){
        Complex tmp;
        tmp.Re = Re * obj.Re - Im * obj.Im;
        tmp.Im = Re * obj.Im + Im * obj.Re;
        return tmp;
    }

    Complex operator*(int a){
        Complex tmp;
        tmp.Re = Re * a - Im * a;
        tmp.Im = Re * a + Im * a;
        return tmp;
    }

    Complex operator+(Complex obj){
        Complex tmp;
        tmp.Re = Re + obj.Re;
        tmp.Im = Im + obj.Im;
        return tmp;
    }

    Complex operator/(double x){
        Complex tmp;
        tmp.Re = Re / x;
        tmp.Im = Im / x;
        return tmp;
    }
};

template <class X> 
X my_cos(X x) {
    X result = 0.0;
    X term = 1.0;
    for (int n = 0; n < N; ++n) {
        result += term;
        term *= -1 * x * x / ((2 * n + 1) * (2 * n + 2));
    }
    return result;
}

int main(){
    double x = M_PI / 4;
    cout << "Cosinus of real number:" << endl;
    cout << "My cos(" << x << ") = " << my_cos(x) << endl;
    cout << "Not my cos(" << x << ") = " << cos(x) << endl;
    cout << "--------------------------------------" << endl;

    cout << "Cosinus of complex number:" << endl;
    Complex z1(1, 2);
    cout << "My cos(" << z1.Re << " + " << z1.Im << "i) = " << my_cos(z1.Re) * cosh(z1.Im) << " - " << sin(z1.Re) * sinh(z1.Im) << "i" << endl;
    complex<double> z2(1, 2); // 1 + 2i
    cout << "Not my cos" << z2 << " = " << cos(z2) << endl;

    return 0;
}
