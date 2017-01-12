#include <cstdio>
 
int m;
void inc(int &x, int y) {
	if ((x += y) >= m)
		x -= m;
}
 
#define N 1000010
int p[N], cnt, lp[N], f[N];
bool np[N];
 
int v[21], c[21], num;
void dfs(int dep, int d, int n) {
	if (dep == num + 1) {
		inc(f[n - d], f[n]);
		//printf("%d %d\n", n, n - d);
		return;
	}
	for (int i = 0; i <= c[dep]; ++i, d *= v[dep])
		dfs(dep + 1, d, n);
}
int main() {
	int n;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		if (!np[i])
			p[++cnt] = lp[i] = i;
		for (int j = 1; j <= cnt && i * p[j] <= n; ++j) {
			np[i * p[j]] = 1;
			lp[i * p[j]] = p[j];
			if (i % p[j] == 0)
				break;
		}
	}
	int last, _n;
	f[n] = 1;
	for (int i = n; i >= 2; --i) {
		last = num = 0;
		_n = i;
		while (_n != 1) {
			if (last != lp[_n]) {
				v[++num] = lp[_n];
				c[num] = 1;
			}
			else
				++c[num];
			last = lp[_n];
			_n /= lp[_n];
		}
		dfs(1, 1, i);
	}
	inc(f[0], f[1]);
	printf("%d", f[0]);
	return 0;
}
