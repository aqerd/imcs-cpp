#include <iostream>
#include <cmath>
using namespace std;

struct ComplTrig {
    double R, Phi;
};

void show(ComplTrig z){
    cout << z.R << "exp = ";
    if (z.Phi > 0.0)
        cout << "i" << z.Phi << endl;
    else if (z.Phi < 0.0)
        cout << "-i" << -z.Phi << endl;
}

// Умножение
ComplTrig mult(ComplTrig x, ComplTrig y){
    ComplTrig z;
    z.R = x.R * y.R;
    z.Phi = x.Phi + y.Phi;
    return z;
}

//Деление
ComplTrig div(ComplTrig x, ComplTrig y){
    ComplTrig z;
    z.R = x.R / y.R;
    z.Phi = x.Phi - y.Phi;
    return z;
}

//Сумма
ComplTrig add(ComplTrig x, ComplTrig y){
    ComplTrig z;
    z.R = sqrt(x.R * x.R + y.R * y.R + 2 * x.R * y.R * cos(x.Phi - y.Phi));
    z.Phi = atan2(x.R*sin(x.Phi)+y.R*sin(y.Phi), x.R*cos(x.Phi)+y.R*cos(y.Phi));
    return z;
}

//Вычитание
ComplTrig sub(ComplTrig x, ComplTrig y){
    y.R = -y.R;
    y.Phi = -y.Phi;
    return add(x, y);
}

int main(){
    ComplTrig x, y, z; 
	x.R = 1.0, x.Phi = 2.0;
	y.R = 3.0, y.Phi = -4.0;
	cout << "x = ";
	show(x);
	cout << "y = ";
	show(y);
	cout << "x + y = ";
	show(z);
	return 0;
}