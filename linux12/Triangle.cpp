#include "Triangle.hpp"
#include <stdio.h>

Triangle::Triangle() {
	width = 1;
	height = 1;
	printf("밑변 %d 높이 %d인 삼각형 생성\n",width,height);
}

Triangle::Triangle(int a, int b) {
	width = a;
	height = b;
	printf("밑변 %d 높이 %d인 삼각형 생성\n", width, height);
}

Triangle::~Triangle() {
	printf("밑변 %d 높이 %d인 삼각형 소멸\n", width, height);
}


double Triangle::getArea() {
	return (width * height / 2.0);
}
