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

int main() {
	pre();
	return 0;
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; ++ i) {
		if (isPar(i)) {
			if (isPrime(i)) {
				printf("%d\n", i);
			}
		}
	}
}

