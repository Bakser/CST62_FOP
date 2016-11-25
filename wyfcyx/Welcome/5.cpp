#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define N 300010
int dx[N], dy[N], nx, ny, x[N], y[N];
int M;
typedef pair<int, int> pii;
pii a[1048576];
pii p[N];
#define fi first
#define se second
pii merge(pii a, pii b) {
	if (a.fi < b.fi)
		return b;
	else if (a.fi > b.fi)
		return a;
	else
		return make_pair(a.fi, a.se + b.se);
}
pii query(int tl, int tr) {
	pii ans = make_pair(-1, 0);
	for (tl += M - 1, tr += M + 1; tl ^ tr ^ 1; tl >>= 1, tr >>= 1) {
		if (~tl & 1)
			ans = merge(ans, a[tl ^ 1]);
		if (tr & 1)
			ans = merge(ans, a[tr ^ 1]);
	}
	return ans;
}
void change(int x, int c) {
	for (a[x += M] = make_pair(c, 1), x >>= 1; x; x >>= 1)
		a[x] = merge(a[x << 1], a[(x << 1) | 1]);
}
 
int c[N], _c[N];
int main() {
	//freopen("tt.in.cpp", "r", stdin);
	int n, q, i, j, k;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		dx[i] = x[i];
		dy[i] = y[i];
	}
	sort(dx + 1, dx + n + 1);
	sort(dy + 1, dy + n + 1);
	nx = unique(dx + 1, dx + n + 1) - dx - 1;
	ny = unique(dy + 1, dy + n + 1) - dy - 1;
	for (i = 1; i <= n; ++i) {
		x[i] = lower_bound(dx + 1, dx + nx + 1, x[i]) - dx;
		y[i] = lower_bound(dy + 1, dy + ny + 1, y[i]) - dy;
		++c[y[i]];
		p[i] = make_pair(x[i], y[i]);
	}
	sort(p + 1, p + n + 1);
	
	for (M = 1; M < (ny + 2); M <<= 1);
	for (i = 1; i < (M << 1); ++i)
		a[i] = make_pair(-1, 0);
	for (i = 1; i <= ny; ++i)
		a[M + i] = make_pair(0, 1);
	for (i = M - 1; i >= 1; --i)
		a[i] = merge(a[i << 1], a[(i << 1) | 1]);
	
	pii ans = make_pair(0, 0);
	pii ask;
	for (i = 1; i <= n; ) {
		for (j = i; j <= n && p[j].fi == p[i].fi; ++j);
		--j;
		//int total = j - i + 1;
		for (k = i; k < j; ++k) {
			if (p[k + 1].se - p[k].se == 1)
				continue;
			ask = query(p[k].se + 1, p[k + 1].se - 1);
			ans = merge(ans, make_pair(min(min(k - i + 1, j - k), ask.fi), ask.se));
		}
		for (k = i; k <= j; ++k) {
			++_c[p[k].se];
			change(p[k].se, min(_c[p[k].se], c[p[k].se] - _c[p[k].se]));
		}
		i = j + 1;
	}
	if (q == 1)
		printf("%d", ans.fi);
	else
		printf("%d", ans.se);
	return 0;
	
}
