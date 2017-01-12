#include <cstdio>
#include <algorithm>
using namespace std;
 
int a[1000010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n & 1)
		printf("%.2lf", (double)a[n >> 1]);
	else
		printf("%.2lf", (a[n >> 1] + a[n / 2 - 1]) / 2.0);
	return 0;
}
