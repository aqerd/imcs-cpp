#include <iostream>
using namespace std;
int N = 1;

class White {
    class Gray {
    public:
        int m;
        Gray *pg;

        Gray(int n) {
            cout << "Gray Created: " << this << endl;
            m = N++;
            if (n > 1) {
                pg = new Gray(n - 1);
            } else {
                pg = nullptr;
            }
        }

        void OutputGray() {
            cout << "Gray Element: " << this << ", Value: " << m << endl;
        }

        void OutputList() {
            OutputGray();
            if (pg != nullptr) {
                pg->OutputList();
            }
        }

        ~Gray() {
            cout << "Gray Deleted: " << this << endl;
            delete pg;
        }
    };

    int m;
    White *pww;
    Gray *pwg;

    void OutputWhite() {
        cout << "White Element: " << this << ", Value: "<< m << endl;
    }

public:
    White(int n) {
        cout << "White Created: " << this << endl;
        m = N++;
        if (n > 1) {
            pww = new White(n - 1);
            pwg = new Gray(n - 1);
        } else {
            pww = nullptr;
            pwg = nullptr;
        }
    }

    void OutputList() {
        OutputWhite();
        if (pww != nullptr) {
            pww->OutputList();
            pwg->OutputList();
        }
    }

    ~White() {
        cout << "White Deleted: " << this << endl;
        delete pww;
        delete pwg;
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