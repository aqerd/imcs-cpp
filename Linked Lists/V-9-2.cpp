#include <iostream>
using namespace std;
int N = 1;

class LinkedList {
    int m;
    LinkedList *pl, *pr;

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
        pl->pl = new LinkedList();
        pr->pr = new LinkedList();
        pl->pl->pr = pr->pr;
        pr->pr->pl = pl->pl;
        if (n > 1) {
            pl->pl->pl = new LinkedList(n - 1);
            pr->pr->pr = pl->pl->pl;
        } else {
            pl->pl->pl = nullptr;
            pr->pr->pr = pl->pl->pl;
        }
    }

    void OutputList() {
        OutputElement();
        pl->OutputElement();
        pr->OutputElement();
        pl->pl->OutputElement();
        pr->pr->OutputElement();
        if (pl->pl->pl != nullptr) {
            pl->pl->pl->OutputList();
        }
    }

    ~LinkedList() {
        cout << "Deleted:" << this << endl;
        if (pl != nullptr && pl->pl->pl != nullptr)
            delete pl->pl->pl;
        if (pl != nullptr) {
            pl->pl->pl = pl->pl->pr = nullptr;
            delete pl->pl;
            pl->pl = pl->pr = nullptr;
            delete pl;
            pr->pr->pl = pr->pr->pr = nullptr;
            delete pr->pr;
            pr->pl = pr->pr = nullptr;
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