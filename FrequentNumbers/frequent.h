#include <map>
using namespace std;

class FrequentNumbers{
    class Node {
    public:
        double m;
        int count;
        bool flagprint;
        Node *prev, *next;
        Node(int value){
            m = value;
            count = true;
            flagprint = true;
            next = nullptr;
            prev = nullptr;
        }
        ~Node(){}
    };

    int s;
    Node *head, *tail;
    void count_list();
    
public:
    FrequentNumbers();
    void push_back(int), output(), print_frequent_numbers(), pop_front(), clear();
    ~FrequentNumbers();
};