#include <cstdio>
 
#define N 10
 
bool d[N][N];
 
int ans, n;
 
#define get(x, i) (((x) >> (i)) & 1)
#define bi(i) (1 << (i))
void dfs(int dep, int a, int b, int c) {
	if (dep == n) {
		++ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (d[dep][i] == 0 && get(a, i) == 0 && get(b, dep + i) == 0 && get(c, dep - i + n - 1) == 0)
			dfs(dep + 1, a | bi(i), b | bi(dep + i), c | bi(dep - i + n - 1));
	}
}
 
int main() {
	int x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &x);
			d[i][j] = x;
		}
	}
	dfs(0, 0, 0, 0);
	printf("%d", ans);
	return 0;
}
