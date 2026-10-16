#include "Sphere.hpp"
#include <stdio.h>

Sphere::Sphere() {
	radius = 1;
	printf("반지름 %d인 구 생성\n",radius);
}

Sphere::Sphere(int a) {
	radius = a;
	printf("반지름 %d인 구 생성\n", radius);
}

Sphere::~Sphere() {
	printf("반지름 %d인 구 소멸\n", radius);
}


double Sphere::getVolume() {
	return 4.0 / 3.0 * PI * radius * radius * radius;
}
