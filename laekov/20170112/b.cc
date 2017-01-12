#include <cstdio>

const int maxn = 503;

int n, a[maxn][maxn], s;

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = n; i > 0; i -= 2) {
		int bi((n - i)>> 1);
		for (int j = 0; j + 1 < i; ++ j) {
			scanf("%d", a[bi] + j + bi);
		}
		for (int j = 0; j + 1 < i; ++ j) {
			scanf("%d", a[bi + j] + (n - bi - 1));
		}
		for (int j = 0; j + 1 < i; ++ j) {
			scanf("%d", a[n - bi - 1] + (n - j - bi - 1));
		}
		for (int j = 0; j + 1 < i; ++ j) {
			scanf("%d", a[n - 1 - bi - j] + bi);
		}
	}
	if (n & 1) {
		scanf("%d", a[(n - 1)>> 1] + ((n - 1)>> 1));
	}
	s = 0;
	int mx((n - 1)>> 1), my(n - 1 - mx);
	for (int i = 0, j, k; i <= mx; ++ i) {
		j = mx - i, k = my + i;
		if (j == k) {
			s += a[j][k];
		} else {
			s += a[j][j] + a[k][j] + a[j][k] + a[k][k];
		}
	}
	printf("%d\n", s);
}
