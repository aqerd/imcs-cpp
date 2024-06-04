#include <iostream>
using namespace std;
int N = 1;

struct LinkedList {
    int m;
    LinkedList *p1;
    LinkedList *p2;
};

LinkedList *MakeElement() {
    LinkedList *q = new LinkedList;
    cout << "Element created: " << q << endl;
    q->m = N++;
    return q;
}

void OutputElement(LinkedList *q) {
    cout << "Element: " << q << ", Value = " << q->m << endl;
}

void DeleteElement(LinkedList *q) {
    cout << "Element deleted: " << q << endl;
    delete q;
}

LinkedList *MakeList(int n ){
    LinkedList *q = MakeElement();
    LinkedList *q1 = MakeElement();
    LinkedList *q2 = MakeElement();
    LinkedList *q3 = MakeElement();
    LinkedList *q4 = MakeElement();
    q->p1 = q1;
    q->p2 = q2;
    q1->p2 = q2;
    q2->p1 = q1;
    q1->p1 = q3;
    q2->p2 = q4;
    q3->p2 = q4;
    q4->p1 = q3;
    if (n > 1) {
        q3->p1 = MakeList(n - 1);
        q4->p2 = q3->p1;
    }
    else {
        q3->p1 = nullptr;
        q4->p2 = nullptr;
    }
    return q;
}

void OutputList(LinkedList *q) {
    OutputElement(q);
    LinkedList *q1, *q2, *q3, *q4;
    q1 = q->p1;
    q2 = q->p2;
    q3 = q1->p1;
    q4 = q2->p2;
    OutputElement(q1);
    OutputElement(q2);
    OutputElement(q3);
    OutputElement(q4);
    if (q3->p1 != nullptr) {
        OutputList(q3->p1);
    }
}

void DeleteList(LinkedList *q) {
    LinkedList *q1, *q2, *q3, *q4, *t;
    q1 = q->p1;
    q2 = q->p2;
    q3 = q1->p1;
    q4 = q2->p2;
    t = q3->p1;
    DeleteElement(q);
    DeleteElement(q1);
    DeleteElement(q2);
    DeleteElement(q3);
    DeleteElement(q4);
    if (t != nullptr) {
        DeleteList(t);
    }
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    LinkedList *q = MakeList(n);
    OutputList(q);
    DeleteList(q);
    return 0;
}