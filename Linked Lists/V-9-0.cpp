#include <iostream>
using namespace std;
int N = 1;

class LinkedList {
    int m;
    LinkedList *p;

    void OutputElement() {
        cout << "Element: " << this << ", Value: " << m << endl;
    }

public:
    LinkedList(int n) {
        cout << "Created: " << this << endl;
        m = N++;
        if (n > 1) {
            p = new LinkedList(n - 1);
        }
        else {
            p = nullptr;
        }
    }

    void OutputList() {
        OutputElement();
        if (p != nullptr) {
            p->OutputList();
        }
    }

    ~LinkedList() {
        cout << "Deleted: " << this << endl;
        delete p;
    }
};

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    LinkedList obj(n);
    obj.OutputList();
    return 0;
}