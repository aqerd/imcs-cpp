#include <iostream>
#include "calc.h"

using namespace std;

/* getop: получает следующий оператор или операнд */
int getop(char *s) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // не число
    i = 0;

    if (c == '-') { // обработка отрицательных чисел
        if (isdigit(c = getch()) || c == '.'){
            s[++i] = c;
        } else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }

    if (isdigit(c)) // накапливаем целую часть
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // накапливаем дробную часть
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}