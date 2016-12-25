#include <cstdio>
 
int main() {
	int s, ans = 0;
	scanf("%d", &s);
	for (int n = 3; (n + 1) * n / 2 <= s; ++n) {
		if ((2 * s) % n == 0) {
			int l = ((2 * s) / n - 2) / (n - 1);
			if (l > 0) {
				int q1 = ((2 * s) / n) & 1, q2 = (n - 1) & 1;
				if (q1 == 0 && q2 == 0)
					ans += l;
				else if (q1 == 0 && q2 == 1)
					ans += l / 2;
				else if (q1 == 1 && q2 == 1)
					ans += (l + 1) / 2;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
