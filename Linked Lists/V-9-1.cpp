#include <iostream>
using namespace std;
int N = 1;

class LinkedList {
    int m;
    LinkedList *pl;
    LinkedList *pr;

    void OutputElement() {
        cout << "Element: " << this << ", Value: " << m << endl;
    }

    LinkedList() {
        cout << "Created: " << this << endl;
        m = N++;
    }

public:
    LinkedList(int n) {
        cout << "Created: " << this << endl;
        m = N++;
        pl = new LinkedList();
        pr = new LinkedList();
        pl->pr = pr;
        pr->pl = pl;
        if (n > 1) {
            pl->pl = new LinkedList(n - 1);
            pr->pr = pl->pl;
        } else {
            pl->pl = nullptr;
            pr->pr = nullptr;
        }
    }

    void OutputList() {
        OutputElement();
        pl->OutputElement();
        pr->OutputElement();
        if (pl->pl != nullptr) {
            pl->pl->OutputList();
        }
    }

    ~LinkedList() {
        cout << "Deleted: " << this << endl;
        if (pl != nullptr) {
            delete pl->pl;
        }
        if (pl != nullptr) {
            pl->pl = pl->pr = nullptr;
            delete pl;
            pr->pr = pr->pl = nullptr;
            delete pr;
        }
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