#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1003;

int n, a[maxn][maxn], f[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= i; ++ j) {
			scanf("%d", a[i] + j);
		}
	}
	f[0][0] = a[0][0];
	for (int i = 1; i < n; ++ i) {
		f[i][0] = f[i - 1][0] + a[i][0];
		f[i][i] = f[i - 1][i - 1] + a[i][i];
		for (int j = 1; j < i; ++ j) {
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
		}
	}
	int ans(f[n - 1][0]);
	for (int i = 1; i < n; ++ i) {
		ans = max(ans, f[n - 1][i]);
	}
	printf("%d\n", ans);
}
