#ifndef _MYLIB_H_
#define _MYLIB_H_

class Sphere {
	int radius;
	const double PI = 3.14159265358979;
public:
	Sphere();
	Sphere(int a);
	double getVolume();
	~Sphere();
};

#endif // !_MYLIB_H_
