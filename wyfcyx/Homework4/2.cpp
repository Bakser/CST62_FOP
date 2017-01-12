#include <cstdio>
 
#define N 13
int f[N][N], C[N][N];
 
int main() {
	int n;
	scanf("%d", &n);
	int i, j, k;
	for (C[0][0] = C[1][0] = C[1][1] = 1, i = 2 ; i <= n; ++i)
		for (C[i][0] = C[i][i] = 1, j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	for (i = 1; i <= n; ++i)
		f[i][1] = 1;
	for (j = 2; j <= n; ++j) {
		for (i = j; i <= n; ++i) {
			for (k = 0; k < i - 1; ++k)
				f[i][j] += f[i - k - 1][j - 1] * C[i - 1][k];
		}
	}
	int ans = 0;
	for (i = 1; i <= n; ++i)
		ans += f[n][i];
	printf("%d", ans);
	return 0;
}
