#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int f[1010][1010], a[1010][1010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; ++i) {
		f[i][1] = f[i - 1][1] + a[i][1];
		f[i][i] = f[i - 1][i - 1] + a[i][i];
		for (int j = 2; j < i; ++j)
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[n][i]);
	printf("%d", ans);
	return 0;
}
