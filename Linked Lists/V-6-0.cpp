#include <iostream>
using namespace std;
int N = 1;

struct LinkedList {
    int m;
    LinkedList *p;
};

LinkedList *MakeElement() {
    LinkedList *q = new LinkedList();
    cout << "Created: " << q << endl;
    q->m = N++; // (*q).m = N++;
    return q;
}

LinkedList *MakeList(int n) {
    LinkedList *q;
    q = MakeElement();
    if (n > 1) {
        q->p = MakeList(n - 1);
    } else {
        q->p = nullptr;
    }
    return q;
}

void OutputElement(LinkedList *q) {
    cout << "Element: " << q << ", Value = " << q->m << endl;
}

void OutputList(LinkedList *q) {
    OutputElement(q);
    if (q->p != nullptr) {
        OutputList(q->p);
    }
}

void DeleteElement(LinkedList *q) {
    cout << "Deleted: " << q << endl;
    delete q;
}

void DeleteList(LinkedList *q) {
    LinkedList *t = q->p;
    DeleteElement(q);
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