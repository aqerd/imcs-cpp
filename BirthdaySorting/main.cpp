#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    string data;
    string name, lastname;
    int day, month, year;
};

//Проверка существования первого файла и подсчет количества строк
int countlines(const string& filename) {
    ifstream source(filename);
    int linesCount = 0;
    string line;
    if (source.is_open()){
        while (getline(source, line)) {
            ++linesCount;
        }
        source.close();
    }
    else {
        linesCount = -1;
    }
    return linesCount;
}

//Вывод из первого файла в массив 
void to_array(const string& filename, Student lines[], const int& n) {
    fstream source(filename);
    int i = 0;
    while (getline(source, lines[i].data) && i < n) {
        ++i;
    }
    source.close();
}

//Функция для обмена значениями (используется в Бабблсорт)
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//Бабблсорт, сортировка массива
void bubblesort(Student lines[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lines[j].year > lines[j + 1].year ||
                (lines[j].year == lines[j + 1].year && lines[j].month > lines[j + 1].month) ||
                (lines[j].year == lines[j + 1].year && lines[j].month == lines[j + 1].month && lines[j].day > lines[j + 1].day)) {
                swap(lines[j], lines[j + 1]);
            }
        }
    }
}

//Вывод из отсортированного массива во второй файл
void to_file(const string& filename, Student lines[], const int& n){
    ofstream output(filename);
    if (output.is_open()) {
        for (int i = 0; i < n; i++) {
            output << lines[i].name << " " << lines[i].lastname << "\t" << lines[i].day << "." << lines[i].month << "." << lines[i].year << endl;
    }
        output.close();
        cout << "Sorted successfully" << endl;
    } else {
        cout << "Error: Troubles with second file" << endl;
    }
}

int main() {
    const string inputfilename = "BirthdayTXT.txt";

    //Подсчет строк в файле
    int n = countlines(inputfilename);
    if (n == -1){
        cout << "Error: Troubles with first file";
        exit(1);
    }

    Student *lines = new Student[n];

    //Внесение данных из файла в массив
    to_array(inputfilename, lines, n);

    //Вывод массива в терминал
    /*for (int i = 0; i < n; ++i) {
        cout << lines[i].data << endl;
    }*/

    //Разделение данных массива по полям структуры
    char dot;
    for (int i=0; i<n; i++){
        istringstream iss(lines[i].data);
        iss >> lines[i].lastname >> lines[i].name;
        iss >> lines[i].day >> dot >> lines[i].month >> dot >> lines[i].year;
    }
    
    //Сортировка
    bubblesort(lines, n);

    //Вывод отсортированных в терминал
    /*for (int i = 0; i < n; i++) {
        cout << lines[i].name << " " << lines[i].lastname << "\t" << lines[i].day << "." << lines[i].month << "." << lines[i].year << endl;
    }*/

    //Вывод во второй файл
    const string outputfilename = "BirthdaySORTED.txt";
    to_file(outputfilename, lines, n);
    
    return 0;
}
