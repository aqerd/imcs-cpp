#include <iostream>
using namespace std;
int N = 1;

class White {
    class Gray {
    public:
        int m;
        Gray *pg;
        White *pw;
        bool flaglast;

        Gray() {
            cout << "Gray created: " << this << endl;
            m = N++;
            pw = nullptr;
        }

        void OutputGray() {
            cout << "Gray element: " << this << ", value: " << m << endl;
        }

        ~Gray() {
            cout << "Gray deleted: " << this << endl;
            if (flaglast != 1)
                delete pw;
            else if (pg != nullptr) {
                pg->pg = nullptr;
                delete pg->pw;
            }
        }
    };

    int m;
    Gray *pwg;

    White() {
        cout << "White created: " << this << endl;
        m = N++;
        pwg = nullptr;
    }

    void OutputWhite() {
        cout << "White element: " << this << ", Value: " << m << endl;
    }

public:
    White(int n) {
        cout << "White created: " << this << endl;
        m = N++;
        White *head1 = this;
        White *head2 = new White;
        Gray *temp1 = head1->pwg = new Gray;
        Gray *temp2 = head2->pwg = new Gray;
        temp2->pg = temp1;
        temp1->pg = temp2;

        for (int i = 1; i < n; i++) {
            temp1->pw = new White;
            temp2->pw = new White;
            temp1->pw->pwg = new Gray;
            temp2->pw->pwg = new Gray;
            temp1 = temp1->pw->pwg;
            temp2 = temp2->pw->pwg;
            temp1->pg = temp2;
            temp2->pg = temp1;
        }

        temp1->flaglast = 1;
        temp2->flaglast = 1;
        temp1->pw = head1;
        temp2->pw = head2;
    }

    void OutputList() {
        White *head1 = this;
        White *head2 = this;
        OutputWhite();

        while (head2->pwg->flaglast != 1) {
            head2 = head2->pwg->pw;
        }
        head2 = head2->pwg->pg->pw;

        head2->OutputWhite();
        pwg->OutputGray();
        head2->pwg->OutputGray();
        
        Gray *temp = pwg;
        while (temp->pw != head1) {
            temp->pw->OutputWhite();
            temp->pg->pw->OutputWhite();
            temp->pw->pwg->OutputGray();
            temp->pg->pw->pwg->OutputGray();
            temp = temp->pw->pwg;
        }
    }

    ~White() {
        cout << "White deleted: " << this << endl;
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