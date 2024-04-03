//  g++ main.cpp getop.cpp stack.cpp getch.cpp -o RPN 
//  ./RPN

#include <iostream>
#include <cstdlib> // для atof()
#include "calc.h"

#define MAXOP 100 // макс. размер операнда или оператора
using namespace std;

/* калькулятор с обратной польской записью */
int main() {
    int type;
    double op2;
    int zerodiv; //флаг для деления на ноль, с ним стек не будет выводить
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        zerodiv = 0;
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else {
                    cout << "Error: Can't divide by zero" << endl;
                    zerodiv = 1;
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else {
                    cout << "Error: Can't find module with  divide by zero" << endl;
                    zerodiv = 1;
                }
                break;
            case '\n':
                if (!zerodiv)
                    cout << pop() << endl;
                break;
            default:
                cout << "Error: Syntaxis " << s << endl;
                break;
        }
    }
    return 0;
}
