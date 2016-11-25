#include <cstdio>
 
int check(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}
 
bool f[10001];
 
int main() {
	int n, x;
	scanf("%d", &n);
	while (n--)
		scanf("%d", &x), f[x] = 1;
	for (int i = 10000; i >= 1; --i)
		if (f[i] && !check(i))
			printf("%d ", i);
	puts("");
	for (int i = 1; i <= 10000; ++i)
		if (f[i] && check(i))
			printf("%d ", i);
	return 0;
}
