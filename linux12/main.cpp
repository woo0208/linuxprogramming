#include "Triangle.hpp"
#include <iostream>

using namespace std;

int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;

	Triangle tri2(2,4);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;

	return 0;
}
