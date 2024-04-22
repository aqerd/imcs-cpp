#include <iostream>
#include <iomanip>
#include "frequent.h"
using namespace std;

FrequentNumbers::FrequentNumbers() {
    s = 0;
    head = nullptr;
    tail = nullptr;
}

void FrequentNumbers::count_list(){
    Node *current = head;
    while (current != nullptr){
        if (current->flagprint){
            Node *NextNode = current->next;
            while (NextNode != nullptr){
                if (current->m == NextNode->m){
                    NextNode->flagprint = false;
                    current->count++;
                }
                NextNode = NextNode->next;
            }
        }
        current = current->next;
    }
}

void FrequentNumbers::print_frequent_numbers(){
    count_list();
    Node *current = head;
    while(current != nullptr){
        if (current->flagprint){
            cout << "Number: " << left << setw(5) << setfill(' ') << (current->m) << "Occurrence: " << current->count << endl;
        }
    current = current->next;
    }
}

void FrequentNumbers::push_back(int number){
    Node* p = new Node(number);
    if (head == nullptr) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    s++;
}
    
void FrequentNumbers::output(){
    Node* current = head;
    while (current != nullptr) {
        cout << current->m << " ";
        current = current->next;
    }
    cout << endl;
}

void FrequentNumbers::pop_front(){
    Node *p = head;
    if (!head){
        cout << "Can't use pop_front, the list is empty" << endl;
        exit(1);
    } else if (head->next) {
        head = head->next;
        delete p;
        s--;
        head->prev = nullptr;
    } else {
        delete p;
        head = tail = nullptr;
        s = 0;
    }
}

void FrequentNumbers::clear(){
    for (int i = 0; i < s; i++){
        pop_front();
    }
}

FrequentNumbers::~FrequentNumbers(){
    clear();
}