#include "Circle.hpp"

Circle::Circle() {
    this->radius = 1;
};

Circle::Circle(int radius) {
    this->radius = radius;
};

bool Circle::operator>(Circle c) {
    return radius > c.radius;
};

int Circle::getRadius() {
    return radius;
};


