#include "mylib.h"
#include <stdio.h>

int one() {
	int a;
	printf("정수 입력:\n");
	scanf_s("%d", &a);
	return a;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void pr(int a,int b) {
	printf("더 큰 수: %d", max(a,b));
}

