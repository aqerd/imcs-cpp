//  g++ main.cpp getop.cpp stack.cpp getch.cpp -o RPN 
//  ./RPN

#include <iostream>
#include <stack>
#include <cstdlib> // для atof()
#include "calc.h"

#define MAXOP 100 // макс. размер операнда или оператора
using namespace std;

/* калькулятор с обратной польской записью */
int main() {
    stack<double> st;
    int type;
    double op2;
    int zerodiv;
    char s[MAXOP];
    cout << "Start typing:" << endl;
    while ((type = getop(s)) != EOF) {
        zerodiv = 0;
        switch (type) {
            case NUMBER:
                st.push(atof(s));
                break;
            case '+':
                op2 = st.top();
                st.pop();
                st.top() += op2;
                break;
            case '*':
                op2 = st.top();
                st.pop();
                st.top() *= op2;
                break;
            case '-':
                op2 = st.top();
                st.pop();
                st.top() -= op2;
                break;
            case '/':
                op2 = st.top();
                st.pop();
                if (op2 != 0.0)
                    st.top() /= op2;
                else {
                    cout << "Error: Can't divide by zero" << endl;
                    zerodiv = 1;
                }
                break;
            case '%':
                op2 = st.top();
                st.pop();
                if (op2 != 0.0)
                    st.top() = (int)st.top() % (int)op2;
                else {
                    cout << "Error: Can't find module with  divide by zero" << endl;
                    zerodiv = 1;
                }
                break;
            case '\n':
                if (!zerodiv) {
                    cout << st.top() << endl;
                    st.pop();
                }
                break;
            default:
                cout << "Error: Syntax " << s << endl;
                break;
        }
    }
    return 0;
}
