#include <cstdio>
#include <cmath>
int main() {
    double a, b, c, p;
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    printf("%.2lf", sqrt(fabs(p * (p - a) * (p - b) * (p - c))));
    return 0;
}
