#include <iostream>

using namespace std;

template <class T>
class Box {
    T data;
public:
    Box(T element);
    void setValue(T element);
    T getValue();
};

template <class T>
Box<T>::Box(T element) {
    data = element;
}

template <class T>
void Box<T>::setValue(T element) {
    data = element;
}

template <class T>
T Box<T>::getValue() {
    return data;
}
