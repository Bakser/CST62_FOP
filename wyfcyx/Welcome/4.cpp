#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define N 10010
#define M 100010
int head[N], nxt[M << 1], to[M << 1], len[M << 1];
void addedge(int a, int b, int c) {
	static int q = 1;
	to[q] = b;
	nxt[q] = head[a];
	len[q] = c;
	head[a] = q++;
}
void make(int a, int b, int c) {
	addedge(a, b, c);
	addedge(b, a, c);
}
 
queue<int> q;
int d[N], mn[N];
bool v[N];
int main() {
	int n, m, i, j, a, b, c;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		make(a, b, c);
	}
	q.push(1);
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	v[1] = 1;
	while (!q.empty()) {
		i = q.front();
		q.pop();
		v[i] = 0;
		for (j = head[i]; j; j = nxt[j])
			if (d[to[j]] > d[i] + len[j]) {
				d[to[j]] = d[i] + len[j];
				if (!v[to[j]]) {
					v[to[j]] = 1;
					q.push(to[j]);
				}
			}
	}
	memset(mn, 0x3f, sizeof mn);
	for (i = 1; i <= n; ++i)
		for (j = head[i]; j; j = nxt[j])
			if (d[to[j]] == d[i] + len[j])
				mn[to[j]] = min(mn[to[j]], len[j]);
	int ans = 0;
	for (i = 2; i <= n; ++i)
		ans += mn[i];
	printf("%d", ans);
	return 0;
}
