#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "coordinates.h"
using namespace std;
const string file = "source.txt";

double Coordinates::GetRadius(){
    ifstream source(file);
    string firstline;
    double radius;
    getline(source, firstline);
    istringstream iss(firstline);
    string useless;
    iss >> useless >> useless >> radius;
    return radius;
}

double Coordinates::calculateDistance(Node* node1, Node* node2) {
    return sqrt(pow(node2->x - node1->x, 2) + pow(node2->y - node1->y, 2) + pow(node2->z - node1->z, 2));
}

bool Coordinates::CheckIfInRadius(Node* node1, Node* node2) {
    double radius = GetRadius(); //// скобки, реализовать в приват функ
    if (sqrt(pow(node1->x, 2) + pow(node1->y, 2) + pow(node1->z, 2)) <= radius){
        if (sqrt(pow(node2->x, 2) + pow(node2->y, 2) + pow(node2->z, 2)) <= radius){
            return true;
        }
    }
    return false;
}    

Coordinates::Coordinates() {
    s = 0;
    head = nullptr;
    tail = nullptr;
}

Coordinates::Node::~Node(){}

void Coordinates::push_back(int i, double x, double y, double z) {
    Node* newNode = new Node(i, x, y, z);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    s++;
}
    
void Coordinates::output() {
    Node* current = head;
    int field = 8;
    cout << left << setw(field) << setfill(' ') << ("i") 
        << setw(field) << setfill(' ') << ("x") 
        << setw(field) << setfill(' ') << ("y") 
        << setw(field) << setfill(' ') << ("z") << endl;
    while (current != nullptr) {
        cout << left << setw(field) << setfill(' ') << (current->i)
            << setw(field) << setfill(' ') << (current->x)
            << setw(field) << setfill(' ') << (current->y)
            << setw(field) << setfill(' ') << (current->z) << endl;
        current = current->next;
    }
}

void Coordinates::LongestVector() {
    double maxDistance = 0;
    Node *startNode = nullptr, *endNode = nullptr;

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        while (nextNode != nullptr) {
            if (CheckIfInRadius(current, nextNode)){
                double distance = calculateDistance(current, nextNode);
                if (distance > maxDistance) {
                    maxDistance = distance;
                    startNode = current;
                    endNode = nextNode;
                }
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }

    if (startNode != nullptr && endNode != nullptr) {
        cout << "Longest vector indexes are: " << startNode->i << " and " << endNode->i << endl << "Distance: " << maxDistance << endl;
    } else {
        cout << "No vectors found" << endl;
    }
}

void Coordinates::pop_front(){
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

void Coordinates::clear(){
    for (int i = 0; i < s; i++){
        pop_front();
    }
}

Coordinates::~Coordinates(){
    clear();
}