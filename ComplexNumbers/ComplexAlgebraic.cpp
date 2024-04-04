#include <iostream>
using namespace std;

struct ComplAlg {
	double Re, Im; //Вещественное и мнимое поле
};

void show(ComplAlg z){
	cout << z.Re;
	if (z.Im > 0.0)
		cout << "+i" << z.Im;
	else if (z.Im < 0.0)
		cout << "-i" << -z.Im;
}

//Сложение
ComplAlg sum(ComplAlg x, ComplAlg y){
	ComplAlg z;
	z.Re = x.Re + y.Re;
	z.Im = x.Im + y.Im;
	return z;
}

//Вычитание
ComplAlg min(ComplAlg x, ComplAlg y){
	ComplAlg z;
	z.Re = x.Re - y.Re;
	z.Im = x.Im - y.Im;
	return z;
}

//Умножение
ComplAlg mult(ComplAlg x, ComplAlg y){
	ComplAlg z;
	z.Re = x.Re * y.Re - x.Im * y.Im;
	z.Im = x.Re * y.Im + x.Im * y.Re;
	return z;
}

//Деление
ComplAlg div(ComplAlg x, ComplAlg y){
	ComplAlg z;
	double module_z = y.Re * y.Re + y.Im * y.Im;
	z.Re = (x.Re * y.Re + x.Im * y.Im) / module_z;
	z.Im = (x.Im * y.Re + x.Re * y.Im) / module_z;
	return z;
}

int main(){
	ComplAlg x, y, z;
	x.Re = 1.0, x.Im = 2.0;
	y.Re = 3.0, y.Im = -4.0;
	cout << "x = ";
	show(x);
	cout << "y = ";
	show(y);
	cout << "x + y = ";
	show(z);
	return 0;
}