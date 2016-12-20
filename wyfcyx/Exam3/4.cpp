#include <cstdio>
#include <algorithm>
int odd(int *d, int c) {
    int num = 0;
    for (int i = c - 1; i > 0; --i)
        num = num * 10 + d[i];
    for (int i = 0; i < c; ++i)
        num = num * 10 + d[i];
    return num;
}
int even(int *d, int c) {
    int num = 0;
    for (int i = c - 1; i >= 0; --i)
        num = num * 10 + d[i];
    for (int i = 0; i < c; ++i)
        num = num * 10 + d[i];
    return num;
}
int pow(int x, int y, int mod) {
    int t = 1;
    for (; y; y >>= 1, x = (long long)x * x % mod) {
        if (y & 1)
            t = (long long)t * x % mod;
    }
    return t;
}
bool check(int x) {
    if (x <= 100) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0)
                return 0;
        }
        return 1;
    }
    else {
        if (pow(2, x - 1, x) != 1) return 0;
        if (pow(3, x - 1, x) != 1) return 0;
        if (pow(5, x - 1, x) != 1) return 0;
        if (pow(7, x - 1, x) != 1) return 0;
        return 1;
    }
}
int q[100010], n;
void work(int x) {
    int d[4], c = 0;
    while (x) {
        d[c++] = x % 10;
        x /= 10;
    }
    if (check(odd(d, c)))
        q[n++] = odd(d, c);
    if (check(even(d, c)))
        q[n++] = even(d, c);
}
int main() {
    for (int i = 1; i < 10000; ++i)
        work(i);
    std::sort(q, q + n);
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < n; ++i) {
        if (q[i] >= a && q[i] <= b)
            printf("%d\n", q[i]);
    }
    return 0;
}
