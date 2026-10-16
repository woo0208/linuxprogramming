#include "mylib.h"

int main() {

	int a, b, c;
	a = b = c= 0;
	a = one();
	b = one();
	c = max(a, b);
	pr(a,b);

	return 0;
}
