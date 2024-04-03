#include <iostream>

#define BUFSIZE 100
char buf[BUFSIZE]; // буфер для ungetch
int bufp = 0; // след, свободная позиция в буфере
using namespace std;

int getch(void) { // взять (возможно возвращенный) символ
    return (bufp > 0) ? buf[--bufp] : cin.get();
}

void ungetch(int c) { // вернуть символ на ввод
    if (bufp >= BUFSIZE)
        cout << "Ungetch: Too many symbols" << endl;
    else
        buf[bufp++] = c;
}