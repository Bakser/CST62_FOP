#include <cstdio>
 
long long f[100001];
int main() {
	int x, y, n;
	scanf("%d%d%d", &n, &x, &y);
	if (x == y) {
		if (n % x != 0)
			puts("sorry");
		else
			printf("1");
	}
	else {
		f[0] = 1;
		for (int i = 0; i <= n; ++i) {
			if (i + x <= n)
				f[i + x] += f[i];
			if (i + y <= n)
				f[i + y] += f[i];
		}
		if (f[n] == 0)
			printf("sorry");
		else
			printf("%lld", f[n]);
	}
	return 0;
}
