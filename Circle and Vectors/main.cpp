#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "coordinates.h"
using namespace std;
const string filename = "source.txt";

int main() {
    Coordinates list;
    
    ifstream source(filename);
    if (!source.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string line;
    int iTemp;
    double xTemp, yTemp, zTemp;
    while (getline(source, line)) {
        istringstream iss(line);
        if (!(iss >> iTemp >> xTemp >> yTemp >> zTemp)) {
            continue;
        }
        list.push_back(iTemp, xTemp, yTemp, zTemp);
    }
    source.close();

    list.output();
    list.LongestVector();

    int k;
    cin >> k;
    return 0;
}
