#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<vector<bool>> VVB;
const string filename = "source.txt";
int n = 0;
int m = 0;

void count_graph() {
    ifstream file(filename);
    int k;
    string line;
    bool passed_once = false;
    while(getline(file, line)) {
        istringstream iss(line);
        while(!passed_once && iss >> k) {
            m++;
        }
        passed_once = true;
        n++;
    }
}

void read_adjacency_matrix(VVB &adjacency) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Can't read file" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            file >> k;
            adjacency[i][j] = k;
        }
    }
    file.close();
}

void print_adjacency_matrix(const VVB &adjacency) {
    cout << "Matrix of Adjency: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacency[i][j] << " ";
        }
        cout << endl;
    }
}

void create_incidence_matrix(const VVB &adjacency, VVB &incidence) {
    incidence.assign(n, vector<bool>(m, 0));
    int edge_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adjacency[i][j] == 1) {
                incidence[i][edge_count] = 1;
                incidence[j][edge_count] = 1;
                edge_count++;
            }
        }
    }
}

void print_incidence_matrix(const VVB &incidence) {
    cout << "Matrix  of Incidence: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < incidence[0].size(); j++) {
            cout << incidence[i][j] << " ";
        }
        cout << endl;
    }
}

void print_edge_list(const VVB &adjacency) {
    cout << "List of Edges: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adjacency[i][j] == 1) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

void print_adjacency_list(const VVB &adjacency) {
    cout << "List of Adjacency: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            if (adjacency[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    count_graph();

    VVB adjacency(n, vector<bool>(n, 0));
    read_adjacency_matrix(adjacency);
    print_adjacency_matrix(adjacency);

    VVB incidence(n, vector<bool>(m, 0));
    create_incidence_matrix(adjacency, incidence);
    print_incidence_matrix(incidence);

    print_edge_list(adjacency);

    print_adjacency_list(adjacency);

    return 0;
}