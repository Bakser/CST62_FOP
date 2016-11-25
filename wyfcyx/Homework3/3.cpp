#include <cstdio>
 
char s[51][51];
 
void fill(int x, int y, int n) {
	for (int i = 1; i < n; ++i, ++y) s[x][y] = '*';
	for (int i = 1; i < n; ++i, ++x) s[x][y] = '*';
	for (int i = 1; i < n; ++i, --y) s[x][y] = '*';
	for (int i = 1; i < n; ++i, --x) s[x][y] = '*';
}
 
int main() {
	int n, _n;
	scanf("%d", &n);
	_n = n;
	int x = 1, y = 1;
	while (_n > 0) {
		fill(x, y, _n);
		_n -= 4;
		x += 2, y += 2;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i][j] == '*')
				putchar('*');
			else
				putchar(' ');
		}
		if (i < n)
			puts("");
	}
	return 0;
}
