#include "shape.hpp"


Shape::Shape() {
    cout << "Shape 생성 ,";
    x = 0;
    y = 0;
}

Shape::Shape(int x,int y) {
    cout << "Shape 생성, ";
    this->x = x;
    this->y = y;
}

void Shape::setCoordinate(int x,int y) {
    this->x = x;
    this->y = y;
}

void Shape::show() {
    cout << "좌표 (" << x << "," << y << ")에 ";
}

Shape::~Shape() {
    cout << "Shape 소멸" << endl;
}

Circle::Circle(int x,int y,int radius) : Shape(x,y) {
    cout << "Circle 생성" << endl;
    this->radius = radius;
}

void Circle::show() {
    Shape::show();
    cout << "반지름 " << radius << "인 원" << endl;
}

Circle::~Circle() {
    cout << "Circle 소멸, ";
}

Rect::Rect(int x,int y,int width,int height) : Shape(x,y) {
    cout << "Rect 생성" << endl;
    this->width = width;
    this->height = height;
}

void Rect::show() {
    Shape::show();
    cout << "폭" << width << ", 높이" << height << "인 직사각형" << endl;
}

Rect::~Rect() {
    cout << "Rect 소멸, ";
}

Triangle::Triangle(int x,int y,int width,int height) : Shape(x,y) {
    cout << "Triangle 생성" << endl;
    this->width = width;
    this->height = height;
}

void Triangle::show() {
    Shape::show();
    cout << "밑변" << width << ", 높이" << height << "인 삼각형" << endl;
}

Triangle::~Triangle() {
    cout << "Triangle 소멸, ";
}
