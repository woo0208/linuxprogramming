#include "mylib.h"

int main() {
    int a,b,sum;
    a = data_input();
    b = data_input();
    sum = add(a,b);
    data_print(sum);
    return 0;
}
