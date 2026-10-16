#ifndef _MYLIB_H_
#define _MYLIB_H_

class Triangle {
	int width;
	int height;
public:
	Triangle();
	Triangle(int a, int b);
	double getArea();
	~Triangle();
};

#endif // !_MYLIB_H_
