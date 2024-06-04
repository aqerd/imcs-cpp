#include <iostream>
using namespace std;
int N = 1;

class LinkedList {
    int m;
    LinkedList* p;
    bool last = false;

    void OutputElement() {
        cout << "Element: " << this << ", Value: " << m << endl;
    }

    LinkedList() {
        cout << "Created: " << this << endl;
    }

public:
    LinkedList(int n) {
        LinkedList *head = nullptr;
        LinkedList *current = this;

        cout << "Created: " << this << endl;
        current->m = N++;
        current->p = nullptr;
        current->last = false;

        head = current;

        for (int i = 1; i < n; i++) {
            current->p = new LinkedList();
            current = current->p;
            current->m = N++;
            current->p = nullptr;
            current->last = false;
        }

        current->p = head;
        current->last = true;
    }

    void OutputList() {
        OutputElement();
        if (!this->last) {
            p->OutputList();
        }
    }

    ~LinkedList() {
        cout << "Deleted: " << this << endl;
        if (!this->last) {
            delete p;
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