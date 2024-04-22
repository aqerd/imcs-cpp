// g++ main.cpp frequent.cpp -o prog

#include <iostream>
#include <fstream>
#include <string>
#include "frequent.h"
using namespace std;
const string filename = "source.txt";

int main(){
    FrequentNumbers list;
    ifstream source(filename);
    if (!source.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    double num;
    while(source >> num){
        list.push_back(num);
    }
    source.close();

    list.output();
    list.print_frequent_numbers();
    // болванка
    /*int k;
    cin >> k;
    return 0;*/
}
