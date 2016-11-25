#include <cstdio>
#include <cstring>
#include <algorithm>
 
int f[11];
int main() {
	int n;
	scanf("%d", &n);
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= n; ++i)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	printf("%d", f[n]);
	return 0;
}
