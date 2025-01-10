#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z, result;

    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    result = add(&x, &y, &z);

    printf("The sum of %d, %d, and %d is %d\n", x, y, z, result);

    return 0;
}


//The priciple of passing by reference is implemented and demonstrated I think.
