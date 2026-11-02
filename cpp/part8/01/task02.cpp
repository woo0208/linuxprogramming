#include <iostream>

using namespace std;

class Shape {
    int x, y;
public:
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    };
    void show() {
        cout << "좌표 (" << x << "," << y << ") 에 ";
    };
};

class Circle : public Shape {
    int radius;
public:
    void setCircle(int x, int y, int radius) {
        set(x, y);
        this->radius = radius;
    };
    void show() {
        Shape::show();
        cout << "반지름 " << radius << "인 원" << endl;
    };
};

class Rect : public Shape {
    int width, height;
public:
    void setRect(int x, int y, int width, int height) {
        set(x, y);
        this->width = width;
        this->height = height;
    };
    void show() {
        Shape::show();
        cout << "폭" << width << ", 높이" << height << "인 직사각형" << endl;
    };
};

class Triangle : public Shape {
    int width, height;
public:
    void setTriangle(int x, int y, int width, int height) {
        set(x, y);
        this->width = width;
        this->height = height;
    };
    void show() {
        Shape::show();
        cout << "밑변" << width << ", 높이" << height << "인 삼각형" << endl;
    };
};


int main() {
    Circle x;
    Rect y;
    Triangle z;
    Shape* shape = nullptr;

    shape = &x;
    ((Circle*)shape)-> setCircle(0, 0, 2);
    ((Circle*)shape)-> show();

    shape = &y;
    ((Rect*)shape)->setRect(1, 1, 5, 10);
    ((Rect*)shape)->show();

    shape = &z;
    ((Triangle*)shape)->setTriangle(2, 2, 3, 4);
    ((Triangle*)shape)->show();

}
