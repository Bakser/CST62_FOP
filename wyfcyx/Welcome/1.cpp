#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, ans = 0, a, b;
	scanf("%d%d", &n, &a);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &b);
		ans = max(ans, a > b ? a - b : b - a);
		a = b;
	}
	printf("%d", ans);
	return 0;
}
