#include <iostream>
#include "calc.h"
#define MAXVAL 100 // максимальная глубина стека
int sp = 0; // следующая свободная позиция в стеке
double val[MAXVAL]; // стек
using namespace std;

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        cout << "Error: stack is full, " << f << endl;
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        cout << "Error: stack is empty" << endl;
        return 0.0;
    }
}