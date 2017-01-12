#include <cstdio>
#include <cstring>
 
int m;
 
void inc(int &x, int y) {
	if ((x += y) >= m)
		x -= m;
}
 
struct Matrix {
	int a[2][2];
	Matrix() {
		memset(a, 0, sizeof a);
	}
 
	void read() {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				scanf("%d", &a[i][j]);
				a[i][j] %= m;
			}
		}
	}
 
	void operator *= (const Matrix &B) {
		Matrix C;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					inc(C.a[i][j], a[i][k] * B.a[k][j] % m);
				}
			}
		}
		*this = C;
	}
};
 
int main() {
	Matrix a;
	int b;
	scanf("%d%d", &b, &m);
	a.read();
	Matrix I;
	I.a[0][0] = I.a[1][1] = 1 % m;
	for (; b; b >>= 1, a *= a)
		if (b & 1)
			I *= a;
	printf("%d %d\n%d %d", I.a[0][0], I.a[0][1], I.a[1][0], I.a[1][1]);
	return 0;
}
