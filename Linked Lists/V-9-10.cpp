#include <iostream>
using namespace std;
int N = 1;

class Grey {
    class White {
    public:
        int m;
        White *w;

        White() {
            cout << "White Created: " << this << endl;
            m = N++;
        }

        void OutputWhite() {
            cout << "White Element: " << this << ", Value: " << m << endl;
        }

        ~White() {
            cout << "White Deleted: " << this << endl;
        }
    };
    
    int m;
    White *pl;
    Grey *pr;

    void OutputGrey() {
        cout << "Grey Element: " << this << ", Value: " << m << endl;
    }

public:
    Grey(int n) {
        cout << "Grey Created: " << this << endl;
        m = N++;
        pl = new White();
        if (n > 1) {
            pr = new Grey(n - 1);
            pl->w = pr->pl;
        } else {
            pr = nullptr;
        }
    }

    void OutputDList() {
        OutputGrey();
        pl->OutputWhite();
        if (pr != nullptr) {
            pr->OutputDList();
        }
    }

    ~Grey() {
        cout << "Grey Deleted: " << this << endl;
        delete pl;
        delete pr;
    }
};

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    Grey obj(n);
    obj.OutputDList();
    return 0;
}
