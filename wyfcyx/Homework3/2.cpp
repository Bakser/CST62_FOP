#include <cstdio>
 
int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	if (h > w)
		h = w;
	for (int j = 1; j <= h; ++j) {
		for (int i = 1; i < j; ++i)
			putchar(' ');
		for (int i = j; i <= w; ++i)
			putchar((((i + j + w) % 2 == 0) ? '-' : '*'));
		if (j < h)
			puts("");
	}
	return 0;
}
