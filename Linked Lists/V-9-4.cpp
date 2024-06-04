#include <iostream>
using namespace std;
int N = 1;

class White {
    class Gray {
    public:
        int m;
        White *pg;

        Gray() {
            cout << "Gray Created: " << this << endl;
            m = N++;
        }

        void OutputGray() {
            cout << "Gray Element: " << this << ", Value: " << m << endl;
        }

        ~Gray() {
            cout << "Gray Deleted: " << this << endl;
        }
    };

    int m;
    Gray *p1, *p2;

    void OutputWhite() {
        cout << "White Element: " << this << ", Value: " << m << endl;
    }

public:
    White(int n) {
        cout << "White Created: " << this << endl;
        m = N++;
        p1 = new Gray();
        p2 = new Gray();
        if (n > 1) {
            p1->pg = new White(n - 1);
            p2->pg = p1->pg;
        } else {
            p1->pg = nullptr;
            p2->pg = nullptr;
        }
    }

    void OutputList() {
        OutputWhite();
        p1->OutputGray();
        p2->OutputGray();
        if (p1->pg != nullptr) {
            p1->pg->OutputList();
        }
    }

    ~White() {
        cout << "White Deleted: " << this << endl;
        White *temp = p1->pg;
        delete p2;
        delete p1;  
        if (temp != nullptr) {
            delete temp;
        }      
    }
};

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    White obj(n);
    obj.OutputList();
    return 0;
}