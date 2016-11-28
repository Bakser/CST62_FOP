#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m, mod;

struct Matrix {
	static const int n = 2;
	int a[n][n];
	Matrix() {
		memset(a, 0, sizeof(a));
	}
	void unit() {
		a[0][0] = a[1][1] = 1 % mod;
		a[0][1] = a[1][0] = 0;
	}
	void read() {
		scanf("%d%d%d%d", a[0], a[0] + 1, a[1], a[1] + 1);
		for (int i = 0; i < 2; ++ i) {
			for (int j = 0; j < 2; ++ j) {
				a[i][j] %= mod;
			}
		}
	}
	void print() {
		printf("%d %d\n%d %d\n", a[0][0], a[0][1], a[1][0], a[1][1]);
	}
	void mul(const Matrix& b) {
		static int s[n][n];
		memset(s, 0, sizeof(s));
		for (int k = 0; k < n; ++ k) {
			for (int i = 0; i < n; ++ i) {
				for (int j = 0; j < n; ++ j) {
					s[i][j] = (s[i][j] + a[i][k] * b.a[k][j])% mod;
				}
			}
		}
		memcpy(a, s, sizeof(s));
	}
};

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	scanf("%d%d", &m, &mod);
	Matrix a, s;
	a.read();
	s.unit();
	for (; m; m >>= 1, a.mul(a)) {
		if (m & 1) {
			s.mul(a);
		}
	}
	s.print();
}
