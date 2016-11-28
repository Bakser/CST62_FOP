#include <cstdio>
 
int f[31];
 
int main() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= 30; ++i)
		f[i] = f[i - 1] + f[i - 2];
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", f[n]);
	return 0;
}
