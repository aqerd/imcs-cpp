#include <string>
using namespace std;

class Coordinates{
    class Node {
    public:
        int i;
        double x, y, z;
        Node *prev;
        Node *next;
        Node(int iValue, double xValue, double yValue, double zValue) {
            i = iValue;
            x = xValue;
            y = yValue;
            z = zValue;
            prev = nullptr;
            next = nullptr;
        }
        ~Node();
    };
    int s;
    Node *head;
    Node *tail;
    double GetRadius(); 
    double calculateDistance(Node*, Node*); 
    bool CheckIfInRadius(Node*, Node*);
public:
    Coordinates();
    void push_back(int i, double x, double y, double z);
    void output(), LongestVector(), pop_front(), clear();
    ~Coordinates();
};
