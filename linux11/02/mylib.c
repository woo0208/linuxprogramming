#include "mylib.h"
#include <stdio.h>

float one() {
	float a;
	printf("1개 정수 입력:\n");
	scanf_s("%f", &a);
	return a;
}

float fun(float a) {
	float res;
	res = ((1.5 * a * a * a) - (3 * a) + 0.7);
	return res;
}

void pr(float a) {
	printf("출력: %0.2f", fun(a));
}

