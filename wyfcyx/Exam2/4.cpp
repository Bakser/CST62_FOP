#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int n, a[2], b[2], c[2];
int dis(int a, int b) {
	return a < b ? b - a : a - b;
}
int cdis(int a, int b) {
	return min(dis(a, b), n - dis(a, b));
}
int m_3(int a, int b, int c) {
	return max(a, max(b, c));
}
 
int main() {
	scanf("%d", &n);
	scanf("%d%d%d", &a[0], &b[0], &c[0]);
	scanf("%d%d%d", &a[1], &b[1], &c[1]);
	int ans = 0;
	for (int _a = 1; _a <= n; ++_a) {
		for (int _b = 1; _b <= n; ++_b) {
			for (int _c = 1; _c <= n; ++_c) {
				if (m_3(cdis(_a, a[0]), cdis(_b, b[0]), cdis(_c, c[0])) <= 2 || m_3(cdis(_a, a[1]), cdis(_b, b[1]), cdis(_c, c[1])) <= 2)
					++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
