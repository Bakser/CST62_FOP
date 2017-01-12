#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20003;
const int maxv = 1e8;

int p[maxn], t;

int reverseDec(int x) {
	int a[11], t(0), s(0);
	for (; x; a[t ++] = x % 10, x /= 10);
	for (int i = 0; i < t; ++ i) {
		s = s * 10 + a[i];
	}
	return s;
}

int isPrime(int x) {
	if (x <= 1) {
		return 0;
	}
	for (int i = 2; i * i <= x; ++ i) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

void check(int i, int u, int b) {
	for (int j = b; i * j + u <= maxv; j *= 10) {
		if (isPrime(i * j + u)) {
			p[t ++] = i * j + u;
		}
	}
}

void pre() {
	t = 0;
	for (int i = 1, b = 1; i < 10000; ++ i) {
		if (b == i) {
			b *= 10;
		}
		int u(reverseDec(i));
		check(i, u, b);
		u = reverseDec(i / 10);
		if (isPrime(i * (b / 10) + u)) {
			p[t ++] = i * (b / 10) + u;
		}
	}
	sort(p, p + t);
	t = unique(p, p + t) - p;
}

int main() {
	pre();
	int a, b;
	scanf("%d%d", &a, &b);
	int *px(lower_bound(p, p + t, a)), *py(upper_bound(p, p + t, b));
	for (int* x = px; x != py; ++ x) {
		printf("%d\n", *x);
	}
}

