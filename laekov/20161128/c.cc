#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 31;

int n, s, a[maxn], b[maxn], c[maxn], p[maxn][maxn];

void DFS(int x) {
	if (x == n) {
		++ s;
		return;
	}
	for (int i = 0; i < n; ++ i) {
		if (!a[i] && !b[i + x] && !c[i - x + n] && !p[i][x]) {
			a[i] = b[i + x] = c[i - x + n] = 1;
			DFS(x + 1);
			a[i] = b[i + x] = c[i - x + n] = 0;
		}
	}
}

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif
	
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			scanf("%d", p[i] + j);
		}
	}
	s = 0;
	DFS(0);
	printf("%d\n", s);
}
