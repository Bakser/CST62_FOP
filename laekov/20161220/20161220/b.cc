#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long dint;
#define _l (long long int)
#ifdef WIN32
#	define lld "%I64d"
#else
#	define lld "%lld"
#endif

int check(int a, int c) {
	if (c < 3) {
		return 0;
	}
	int p(a * 2 / c), q(c - 1), s(0);
	if ((p & 1) && (q & 1)) {
		s = (p / q + 1)>> 1;
	} else if (!(p & 1) && (q & 1)) {
		s = (p / q)>> 1;
	} else if (!(p & 1) && !(q & 1)) {
		s = p / q;
	}
	if (p % q == 0) {
		-- s;
	}
	return max(s, 0);
}

dint sovB(int x) {
	int y(x << 1);
	dint ans(0);
	for (int i = 2; i * i <= y; ++ i) {
		if (y % i) {
			continue;
		}
		if (i > 2) {
			ans += check(x, i);
		}
		if (y != i * i) {
			ans += check(x, y / i);
		}
	}
	return ans;
}

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	int a;
	scanf("%d", &a);
	printf(lld "\n", sovB(a));
}
