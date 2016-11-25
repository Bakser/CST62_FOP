#include <cstdio>
 
int c[11][11];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for (c[0][0] = 1, i = 1; i < n; ++i) {
		for (c[i][0] = c[i][i] = 1, j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (i = 0; i < n; ++i) {
		if (i)
			puts("");
		printf("%d", c[i][0]);
		for (j = 1; j <= i; ++j)
			printf(" %d", c[i][j]);
	}
	return 0;
}
