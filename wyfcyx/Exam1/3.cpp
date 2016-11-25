#include <cstdio>
#include <cstring>
 
int a[3], b[3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= 3; ++i) {
		int c = 0;
		for (int j = 0; j < 3; ++j)
			if (i == a[j])
				c += 1 - b[j];
			else
				c += b[j];
		if (c == n)
			printf("%d", i);
	}
	return 0;
} 
