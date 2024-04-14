#include <iostream>
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
    MyList(){
        s = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int n){
        Node *p = new Node(n);
        if (!head){
            head = p;
            tail = p;
        } else {
            tail->next = p;
            p->prev = tail;
            tail = p;
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
            head = p;
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
                Node *pPrev = p->prev;
                while (pPrev != nullptr && pPrev->m > key){
                    pPrev->next->m = pPrev->m;
                    pPrev = pPrev->prev;
                }
                if (pPrev == nullptr)
                    head->m = key;
                else
                    pPrev->next->m = key;
                p = p->next;
            }
        }
    }

    void clear(){
        for (int i = 0; i < s; i++){
            pop_front();
        }
    }

    void insert(int i, int n){
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
    }

    int size(){
        return s;
    }

    void erase(int n){
        if (n < 0 || n > s){
            cout << "Error: erase" << endl;
            exit(1);
        } 
        if (n == 0) {
            pop_front();
            return;
        }
        if (n == s-1) {
            pop_back();
            return;
        }
        Node *p;
        if (n <= s/2) {
            p = head;
            while (n > 0) {
                p = p->next;
            }
        } else {
            p = tail;
            for (int i = s-1; i > n; i--)
                p = p->prev;
        }
        Node *pPrev = p->prev;
        Node *pNext = p->next;
        delete p;
        pPrev->next=pNext;
        pNext->prev=pPrev;
        s--;
    }

    void erasebypointer(Node *t){
        if (t==head){
            pop_front();
            return;
        }
        if (t==tail){
            pop_back();
            return;
        }
        Node *pPrev = t->prev;
        Node *pNext = t->next;
        delete t;
        pNext->prev = pPrev;
        pPrev->next = pNext;
        s--;        
    }

    void OutputDList(){
        Node *p = head;
        while(p){
            cout << p->m << " ";
            p = p->next;
        }
        cout << endl;
    }

    ~MyList(){
        clear();
    }
};

/*void OutputDList(list<int> my_obj){
    for (auto q = my_obj.begin(); q != my_obj.end(); ++q)
        cout << *q << ' ';
    cout << endl;
}*/

int main(){
    int n;
    MyList my_obj;

    //Добавляет элементы вперед и назад
    my_obj.push_back(5);
    my_obj.push_back(2);
    my_obj.push_back(-6);
    my_obj.push_back(-1);
    my_obj.push_front(3);
    my_obj.push_front(4);
    my_obj.push_front(1);
    my_obj.push_front(10);

    //Убирает первые или последние элементы
    /*my_obj.pop_front();
    my_obj.pop_back();*/

    //Сортировка вставками
    cout << "Before sorting: ";
    my_obj.OutputDList();
    my_obj.sort();
    cout << "After sorting: ";
    my_obj.OutputDList();

    // Определяет размер списка
    cout << "Size: " << my_obj.size() << endl;

    //Очищает списки
    my_obj.clear();
    cout << "Cleared: ";
    my_obj.OutputDList();

    //Добавляет список между какими-либо другими списками
    /*cout << "n = ";
    cin >> n;
    my_obj.insert(n, 3);*/

    //Вывод первого элемента
    /*//list<int>::iterator q = my_obj.begin(); //Первый вариант присваивания
    //auto q = my_obj.begin(); //Второй вариант присваивания
    //cout << "First: "<< *q << endl;*/

    //Вывод всех элементов
    /*cout << "All: "; 
    OutputDList(my_obj);*/

    return 0;
}
