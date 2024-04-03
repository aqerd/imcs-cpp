#include <iostream>
#include <list>
using namespace std;

class MyList{
    class Node{
    public:
        int m;
        Node *next, *prev;
        Node(int N){
            m = N;
            next = nullptr;
            prev = nullptr;
        }
        ~Node(){}
    };
    int s;
    Node *head, *tail;
    
    public:
    MyList(int s){
        s = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int n){
        Node *p;
        if (head == nullptr){
            head=tail=p;
        } else {
            tail->next=p;
            p->prev=tail;
            tail=p;
        }
        s++;
    }

    void push_front(int n){
        Node *p = new Node(n);
        if (!head){
            head = p;
            tail = p;
        } else {
            p->next=head;
            head->prev=p;
        }
        s++;
    }

    void pop_front(){
        Node *p = head;
        if (!head){
            cout << "Error: can't use pop_front, the list is already empty" << endl;
            exit(1);
        } else {
            head=head->next;
            delete p;
            s--;
            head->prev=nullptr;
        }
    }

    void pop_back(){
        Node *p = tail;
        if (!head){
            cout << "Error: can't use pop_back, the list is already empty" << endl;
            exit(1);
        } else {
            tail=tail->prev;
            delete p;
            s--;
            tail->next=nullptr;
        }
    }

    void sort(){
        if (head != nullptr && head->next != nullptr) {
            Node *p = head->next;
            while (p != nullptr){
                int key = p->m;
                Node *prev = p->prev;
                while (prev != nullptr && prev->m > key){
                    prev->next->m = prev->m;
                    prev = prev->prev;
                }
                if (prev == nullptr)
                    head->m = key;
                else
                    prev->next->m = key;
                p = p->next;
            }
        }
    }

    void clear(){
        for (int i = 0; i < s; i++){
            pop_front();
        }
    }

    /*void insert(int i, int n){
        if (i < 0 || i > s){
            cout << "Error: insert" << endl;
            exit(1);
        } 
        if (i == 0) {
            push_front(n);
        } else if (i == s) {
            push_back(n);
        } else {
            Node *p = new Node(n);
            Node *tPrev;
            Node *tNext;
            if (i < s/2) {
                tPrev = head;
                for (int j = 0; j < i; j++){
                    tPrev = tPrev->next;
                }
            } else {
                tNext = tail;
                for (int  j = s-1; j > i+1; j++){
                    tNext = tNext->prev;
                }
                tPrev=tNext->prev;
            }
            p->prev=tPrev;
            p->next=tNext;
            tNext->prev=p;
            tPrev->next=p;
            s++;
        }
    }*/

    int size(){
        return s;
    }

    void OutputDList(){
        Node *p = head;
        for(int q = 0; q<s; q++){
            cout << "Element: " << p->m << ' ';
            p=p->next;
        }
        cout << endl;
    }

    ~MyList(){
        clear();
    }
};

void OutputDList(list<int> obj){
    for (auto q = obj.begin(); q != obj.end(); ++q)
        cout << *q << ' ';
    cout << endl;
}

int main(){
    int n;
    list<int> obj;

    //Добавляет элементы вперед и назад
    obj.push_back(5);
    obj.push_back(2);
    obj.push_front(3);
    obj.push_front(4);
    obj.push_back(-6);
    obj.push_back(-1);
    obj.push_front(1);
    obj.push_front(10);

    //Убирает первые или последние элементы
    /*obj.pop_front();
    obj.pop_back();*/

    //Сортировка вставками
    cout << "Before sorting: ";
    OutputDList(obj);
    obj.sort();
    cout << "After sorting: ";
    OutputDList(obj);

    // Определяет размер списка
    int k = obj.size();
    cout << "Size: " << k << endl;

    //Очищает списки
    //obj.clear();

    //Добавляет список между какими-либо другими списками
    /*cout << "n = ";
    cin >> n;
    obj.insert(n, 3);*/

    //Вывод первого элемента
    /*//list<int>::iterator q = obj.begin(); //Первый вариант присваивания
    //auto q = obj.begin(); //Второй вариант присваивания
    //cout << "First: "<< *q << endl;*/

    //Вывод всех элементов
    cout << "All: "; 
    OutputDList(obj); 
    return 0;
}
