#include <cstdio>
#include <cstring>
 
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i; ++j)
			putchar(' ');
		for (int j = 1; j <= i; ++j) {
			if (j > 1)
				putchar(' ');
			putchar('*');
		}
		puts("");
	}
	return 0;
} 
