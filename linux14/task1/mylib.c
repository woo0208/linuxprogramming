#include <stdio.h>

int data_input() {
    int a;
    printf("Input:");
    scanf("%d",&a);
    return a;
}

int add(int a,int b) {
    return (a + b);
}

void data_print(int sum) {
    printf("Sum:%d\n",sum);
}
