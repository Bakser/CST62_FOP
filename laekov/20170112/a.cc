#include <cstdio>

int main() {
	int n, s1(1), s2(1);
	scanf("%d", &n);
	s1 = 1, s2 = 8;
	for (int i = 1; i < n; ++ i) {
		int ns2(s1 + s2 * 9);
		int ns1(s1 * 9 + s2);
		s1 = ns1;
		s2 = ns2;
	}
	printf("%d\n", s2);
}
