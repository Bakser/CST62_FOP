#include <cstdio>
int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%.2lf", 2 * (a * b + a * c + b * c));
    return 0;
}
