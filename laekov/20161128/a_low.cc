#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long dint;

const int maxn = 103;

dint nst[maxn];
int sst[maxn], tst;
char tmp[maxn];

void pushChar(char x) {
	if (isdigit(x)) {
		nst[tst] = nst[tst] * 10 + x - 48;
	} else if (x == '+' || x == '-') {
		while (sst[tst] == 0) {
			nst[tst - 1] *= nst[tst];
			-- tst;
		}
		sst[++ tst] = (x == '+') ? 1 : -1;
		nst[tst] = 0;
	} else if (x == '*') {
		sst[++ tst] = 0;
		nst[tst] = 0;
	}
}

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	scanf("%s", tmp);
	tst = 1;
	sst[1] = 1, nst[1] = 0;
	for (char* i = tmp; *i; ++ i) {
		pushChar(*i);
	}
	while (sst[tst] == 0) {
		nst[tst - 1] *= nst[tst];
		-- tst;
	}
	dint ans(0);
	for (int i = 1; i <= tst; ++ i) {
		ans += nst[i] * sst[i];
	}
	printf("%d\n", (int)ans);
}

