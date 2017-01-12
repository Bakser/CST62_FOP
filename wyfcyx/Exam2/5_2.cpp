#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cctype> 
#include <cstring>
using namespace std;
 
int getc() {
	static const int L = 1 << 15;
	static char buf[L], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, L, stdin);
		if (S == T)
			return EOF;
	}
	return *S++;
}
int getint() {
	int c;
	while (!isdigit(c = getc()));
	int x = c - '0';
	while (isdigit(c = getc()))
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}
 
int f[2][1010];
int main() {
	//freopen("tt.in", "r", stdin);
	int n = getint();
	int now = 0, last = 1;
	f[now][1] = getint();
	for (int i = 2; i <= n; ++i) {
		swap(now, last);
		memset(f[now], 0, sizeof f[now]);
		for (int j = 1; j <= i; ++j) {
			if (j == 1)
				f[now][1] = f[last][1] + getint();
			else if (j == i)
				f[now][i] = f[last][i - 1] + getint();
			else
				f[now][j] = max(f[last][j], f[last][j - 1]) + getint();
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[now][i]);
	printf("%d", ans);
	return 0;
}
