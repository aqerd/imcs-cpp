#include <iostream>
#include <cmath>
const int N = 5;
using namespace std;

struct Point{
    double x, y;
};

double distance(Point A, Point B){
    return sqrt(pow((B.x-A.x), 2) + pow((B.y-A.y), 2));
}

void maxdistance(Point *P){
    int maxA, maxB;
    double maxdist = 0, r;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            r = distance(P[i], P[j]);
            if (r > maxdist)
                maxdist = r;
                maxA = i;
                maxB = j;
        }
    }
    cout << "Points: " << maxA << ", " << maxB << ". Distance: " << maxdist << endl;
}

int main(){
    Point P[N];
    P[0].x = 1;
    P[0].y = 5;
    P[1].x = 3;
    P[1].y = 9;
    P[2].x = 4;
    P[2].y = 16;
    P[3].x = 1;
    P[3].y = 5;
    P[4].x = 10;
    P[4].y = 12;
    maxdistance(P);
}
