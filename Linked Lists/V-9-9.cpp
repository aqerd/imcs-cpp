#include <iostream>
using namespace std;
int N = 1;

class Gray {
    class White {
    public:
        int m;
        White() {
        cout << "White Created: " << this << endl;
        m = N++;
        }

        void OutputWhite() {
            cout << "White Element:" << this << ", Value: "<< m << endl;
        }

        ~White() {
            cout << "White Deleted: " << this << endl;
        }
    };
    int m;
    Gray *p1;
    White *p2;

    void OutputGrey() {
        cout << "Gray Element: " << this << ", Value: " << m << endl;
    }

public:
    Gray(int n) {
        cout << "Gray Created: " << this << endl;
        m=N++;
        p2 = new White();
        if (n>1) {
            p1 = new Gray(n - 1);
        }
        else{
            p1 = nullptr;
        }
    }
    
    void OutputList() {
        OutputGrey();
        p2->OutputWhite();
        if (p1!=nullptr)
            p1->OutputList();
    }

    ~Gray() {
        cout << "Gray Deleted: " << this << endl;
        delete p2;
        delete p1;
    }
};

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    Gray obj(n);
    obj.OutputList();
}