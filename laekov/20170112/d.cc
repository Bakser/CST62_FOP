#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 103;

int n, a[maxn];

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++ i) {
		int j(i);
		for (int k = i + 1; k < n; ++ k) {
			if (a[k] < a[j]) {
				j = k;
			}
		}
		printf("swap(a[%d], a[%d]):", i, j);
		swap(a[i], a[j]);
		for (int k = 0; k < n; ++ k) {
			printf("%d ", a[k]);
		}
		putchar(10);
	}
}
