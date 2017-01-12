#include <cstdio>

const int maxn = 103;

int n, a[maxn], t;

int main() {
	scanf("%d", &n);
	t = 0;
	for (int i = 30; i >= 0; -- i) {
		if (n & (1 << i)) {
			a[t ++] = i;
		}
	}
	for (int i = 0; i < t; ++ i) {
		if (i) {
			putchar('+');
		}
		printf("2(%d)", a[i]);
	}
	putchar(10);
}
