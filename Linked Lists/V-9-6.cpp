#include <iostream>
using namespace std;
int N = 1;
#define size 5

class LinkedList {
    int m;
    LinkedList *p[size];

    void OutputElement() {
        cout << "Element:" << this << ", Value: "<< m << endl;
    }

public:
    LinkedList(int n) {
        cout << "Created: " << this << endl;
        m = N++;
        if (n > 1) {
            for (int i = 0; i <= size; i++) {
                p[i] = new LinkedList(n - 1);
            }
        } else {
            for (int i = 0; i < size; i++) {
                p[i] = nullptr;
            }
        }
    }

    void OutputList() {
        OutputElement();
        if (p[0] != nullptr) {
            for (int i = 0; i < size; i++) {
                p[i]->OutputList();
            }
        }
    }

    ~LinkedList() {
        cout << "Deleted: " << this << endl;
        for (int i = 0; i < size; i++) {
            delete p[i];
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