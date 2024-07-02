#include <stdio.h>

/* typedef int (*fptradd)(int, int);
fptradd getadd()
{
    return sum; // return func itself, sum() return var itself
} */

int sum(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a > b ? a - b : b - a;
}

int mul(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    // Assuming div results in an integer
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0; 
    }
}
enum {
    Sum,
    Subtract,
    Mul,
    Divide
};
int (*ArrPtr[])(int, int) = {
    &sum,
    &subtract,
    &mul,
    &divide
};


int main(){
    /* fptradd fptr1;
    fptr1 = &sum; */
    //int (*fptr) (int, int) = &sum;
    //printf("%d", fptr1(1, 2));
    printf("sum - %d\n", (*ArrPtr[Sum])(1, 2));
    printf("subtract - %d\n", (*ArrPtr[Subtract])(1, 2));
    printf("mul - %d\n", (*ArrPtr[Mul])(1, 2));
    printf("div - %d\n", (*ArrPtr[Divide])(1, 2));
    return 0;
}