#include <iostream>
#include "shape.hpp"


using namespace std;

int main() {
    Circle x(0,0,2);
    Rect y(1,1,5,10);
    Triangle z(2,2,5,10);
    x.show();
    y.show();
    z.show();
}
