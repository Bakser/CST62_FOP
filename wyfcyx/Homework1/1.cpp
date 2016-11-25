#include <cstdio>
#include <cmath>
int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2lf", r * r * acos(-1.0));
    return 0;
}
