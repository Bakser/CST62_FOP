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

dint sovB(int x) {
	dint ans(0);
	for (int i = 1; i <= x; ++ i) {
		for (int j = 1; j <= x; ++ j) {
			int s(0), k(0);
			for (; s < x; ++ k) {
				s += i + j * k;
			}
			if (s == x && k > 2) {
				printf("%d %d %d\n", i, j, k);
				++ ans;
			}
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
