#include <iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle();
    Circle(int radius);
    bool operator>(Circle c);
    int getRadius();
};

template <class T>
T bigger(T a, T b) {
    if (a > b) return a;
    else return b;
}
