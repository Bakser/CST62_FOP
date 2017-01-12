#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000003;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	printf("%.2lf\n", ((double)a[n >> 1] + a[(n - 1) >> 1])/ 2.0);
}
