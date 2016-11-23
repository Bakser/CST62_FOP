#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int x[2][3], n, tot, a[259];

void calc(int* a, int p, int s) {
	if (p == 3) {
		::a[tot ++] = s;
	} else {
		for (int i = -2; i <= 2; ++ i) {
			calc(a, p + 1, s * n + (a[p] + i + n)% n);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2; ++ i) {
		for (int j = 0; j < 3; ++ j) {
			scanf("%d", x[i] + j);
		}
	}
	tot = 0;
	calc(x[0], 0, 0);
	calc(x[1], 0, 0);
	sort(a, a + tot);
	printf("%d\n", unique(a, a + tot) - a);
}
