#include <stdio.h>
#include <iostream>

using namespace std;

class Shape {
    int x,y;
public:
    Shape();
    Shape(int x, int y);
    void show();
    ~Shape();
};

class Circle : public Shape {
    int radius;
public:
    Circle(int x,int y,int radius);
    void show();
    ~Circle();
};

class Rect : public Shape {
    int width, height;
public:
    Rect(int x,int y,int width, int height);
    void show();
    ~Rect();
};

class Triangle : public Shape {
    int width, height;
public:
    Triangle(int x,int y,int width,int height);
    void show();
    ~Triangle();
};
