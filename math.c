#include <stdio.h>
#include <math.h>

int x = 2;
int y = 3;

int main(void)
{
    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("x + y is %i\n", x + y);
    printf("x - y is %i\n", x - y);
    printf("x * y is %i\n", x * y);
    printf("x / y is %i\n", x / y);
    printf("x %% y is %i\n", x % y);
    printf("x ^ y is %f\n", pow(x, y));
    return 0;
