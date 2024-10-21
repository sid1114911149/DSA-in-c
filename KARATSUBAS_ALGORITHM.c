#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getSize(int num) {
    int size = 0;
    while (num != 0) {
        size++;
        num /= 10;
    }
    return size;
}
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
int karatsuba(int x, int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }
    int size = fmin(getSize(x), getSize(y));
    int halfSize = size / 2;
    int a = x / power(10, halfSize);
    int b = x % power(10, halfSize);
    int c = y / power(10, halfSize);
    int d = y % power(10, halfSize);
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_bc = karatsuba(a + b, c + d) - ac - bd;
    return ac * power(10, 2 * halfSize) + ad_bc * power(10, halfSize) + bd;
}
int main() {
    int num1,num2;
    printf("enter numbers:");
    scanf("%d %d",&num1,&num2);
    int result = karatsuba(num1, num2);
    printf("Product of %d and %d is %d\n", num1, num2, result);
    return 0;
}
