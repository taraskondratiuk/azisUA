#include<stdio.h>
#include<math.h>


#define PI 3.14


long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

double sinN(double x, int n) {
    return pow(-1, n) * pow(x, (2 * n) + 1) / factorial(2 * n + 1);
}

double sinWithPrecision(double x, double precision) {
    double res = x;
    double prevRes;

    int n = 1;
    do {
        prevRes = res;
        res += sinN(x, n);
        n++;
    } while (fabs(res - prevRes) > precision);
    return res;
}

double userCounter(double x, double precision) {
    return (sinWithPrecision(3 * PI * x / 12, precision) + 5) /
           (sinWithPrecision(5 * PI * x / 8, precision) + 3);
}

double libCounter(double x) {
    return (sin(3 * PI * x / 12) + 5) /
           (sin(5 * PI * x / 8) + 3);
}

int main(void) {

    double x, precision;
    // (|5 * pi * x / 8|) should be in [-1, 1]
    printf("Enter x [-0.5, 0.5] : ");
    scanf("%lf", &x);

    printf("Enter precision : ");
    scanf("%lf", &precision);

    printf("Counted with user function : %.20lf", userCounter(x, precision));
    printf("\nCounted with lib function : %.20lf", libCounter(x));
}