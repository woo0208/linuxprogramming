#include "Circle.hpp"



int main() {
    int a=20, b=50,c;
    c = bigger(a,b);
    cout << "20과 50중 큰 값은 " << c << endl;

    Circle donut(10),pizza(20),y;
    y = bigger(donut,pizza);
    cout << "donut과 pizza중 큰 반지름은 " << y.getRadius() << endl;
    return 0;
}
