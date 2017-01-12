#include <cstdio>
#include <cstring>
 
int d[4];
int main() {
	for (int i = 1000; i <= 9999; ++i) {
		int n = i;
		for (int j = 3; j >= 0; --j)
			d[j] = n % 10, n /= 10;
		if (i * 4 == 1000 * d[3] + 100 * d[2] + 10 * d[1] + d[0])
			printf("%d", i);
	}
	return 0;
} 
