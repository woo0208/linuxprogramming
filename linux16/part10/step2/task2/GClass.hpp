#include <iostream>

using namespace std;

template <class T1, class T2>
class GClass {
    T1 value1;
    T2 value2;
public:
    GClass();
    void set(T1 v1, T2 v2);
    void get(T1 &v1, T2 &v2);
    void swap();
};

template <class T1, class T2>
GClass<T1,T2>::GClass() {
    value1 = 0;
    value2 = 0;
}

template <class T1, class T2>
void GClass<T1,T2>::set(T1 v1, T2 v2) {
    value1 = v1;
    value2 = v2;
}

template <class T1, class T2>
void GClass<T1,T2>::get(T1 &v1, T2 &v2) {
    v1 = value1;
    v2 = value2;
}

template <class T1, class T2>
void GClass<T1,T2>::swap() {
    T1 value3;
    value3 = value1;
    value1 = value2;
    value2 = value3;
}
