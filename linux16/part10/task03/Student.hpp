#include <iostream>
#include <string>

using namespace std;

class Student {
    int id;
    string name;
    double score;
public:
    Student(int id, string name, double score);
    bool operator>(Student s);
    bool operator==(Student s);
    string getname();
};

template <class T>
T bigger(T a, T b) {
    if (a > b) return a;
    else return b;
}

template <class T>
bool isSame(T a, T b) {
    return a == b;
}
