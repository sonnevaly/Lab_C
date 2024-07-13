#include <stdio.h>

void Power(float *x, const int n) {
    float result = 1.0;
    int i;
    for (i = 0; i < n; i++) {
        result *= *x;
    }
    *x = result;
}

int main() {
    float x, y;
    int n;

    printf("Enter the base number (x): ");
    scanf("%f", &x);

    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    Power(&x, n);

    printf("Result of x power n: %.2f\n", x);

    return 0;
}
