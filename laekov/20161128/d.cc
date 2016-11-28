#include <cstdio>

const int maxn = 33;

int f[maxn];

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; ++ i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", f[n]);
	}
}
