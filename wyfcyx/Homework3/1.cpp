#include <cstdio>
char s[52][52];
 
void p(int x, int y, int z) {
	s[x][y] = 'A' + z - 1;
}
int main() {
	int n;
	scanf("%d", &n);
	int x, y, z;
	for (int i = 1; i <= 2 * n - 1; ++i)
		for (int j = 1; j <= 2 * n - 1; ++j)
			s[i][j] = '.';
	for (x = y = z = 1; z <= n; ++z, ++x, ++y) p(x, y, z);
	for (x = z = 1, y = n; z <= n; ++z, ++x) p(x, y, z);
	for (x = z = 1, y = 2 * n - 1; z <= n; ++z, ++x, --y) p(x, y, z);
	for (x = n, y = z = 1; z <= n; ++z, ++y) p(x, y, z);
	for (x = n, y = 2 * n - 1, z = 1; z <= n; ++z, --y) p(x, y, z);
	for (x = 2 * n - 1, y = z = 1; z <= n; ++z, --x, ++y) p(x, y, z);
	for (x = 2 * n - 1, y = n, z = 1; z <= n; ++z, --x) p(x, y, z);
	for (x = y = 2 * n - 1, z = 1; z <= n; ++z, --x, --y) p(x, y, z);
	for (int i = 1; i <= 2 * n - 1; ++i) {
		for (int j = 1; j <= 2 * n - 1; ++j)
			putchar(s[i][j]);
		puts("");
	}
	return 0;
}
