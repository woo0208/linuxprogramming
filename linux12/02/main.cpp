#include "Sphere.hpp"
#include <iostream>

using namespace std;

int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVolume() << endl;

	Sphere sph2(3);
	cout << "구의 부피는 " << sph2.getVolume() << endl;

	return 0;
}
