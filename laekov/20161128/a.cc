#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long dint;

const int maxn = 103;

struct BigInt {
	int n, a[maxn];
	BigInt() {
		n = 0;
	}
	void zero() {
		n = 0;
	}
	void push(int x) {
		for (int i = n; i; -- i) {
			a[i] = a[i - 1];
		}
		a[0] = x;
		++ n;
	}
	void print() {
		if (n == 0) {
			putchar(48);
		}
		for (int i = n - 1; i >= 0; -- i) {
			putchar(a[i] + 48);
		}
		putchar(10);
	}
	void pushBits() {
		for (int i = 0; i + 1 < n; ++ i) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		for (; a[n - 1] >= 10; ++ n) {
			a[n] = a[n - 1] / 10;
			a[n - 1] %= 10;
		}
	}
	void pullBits() {
		for (; n && !a[n - 1]; -- n);
	}
	void mul(BigInt& y) {
		static int tmp[maxn];
		int tot(n + y.n);
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < y.n; ++ j) {
				tmp[i + j] += a[i] * y.a[j];
			}
		}
		memcpy(a, tmp, tot * sizeof(int));
		n = tot;
		pushBits();
		pullBits();
	}
	void add(BigInt& y) {
		static int tmp[maxn];
		for (int i = 0; i < n && i < y.n; ++ i) {
			tmp[i] = a[i] + y.a[i];
		}
		for (int i = min(n, y.n); i < n; ++ i) {
			tmp[i] = a[i];
		}
		for (int i = min(n, y.n); i < y.n; ++ i) {
			tmp[i] = y.a[i];
		}
		n = max(n, y.n);
		memcpy(a, tmp, n * sizeof(int));
		pushBits();
	}
	void substract(BigInt& y) {
		for (int i = 0; i < y.n; ++ i) {
			a[i] -= y.a[i];
			if (a[i] < 0) {
				-- a[i + 1];
				a[i] += 10;
			}
		}
		for (int i = y.n; i < n && a[i] < 0; ++ i) {
			a[i] += 10;
			-- a[i + 1];
		}
		pullBits();
	}
};

BigInt nst[maxn];
int sst[maxn], tst;
char tmp[maxn];

void pushChar(char x) {
	if (isdigit(x)) {
		nst[tst].push(x - 48);
	} else if (x == '+' || x == '-') {
		while (sst[tst] == 0) {
			nst[tst - 1].mul(nst[tst]);
			-- tst;
		}
		sst[++ tst] = (x == '+') ? 1 : -1;
		nst[tst].zero();
	} else if (x == '*') {
		sst[++ tst] = 0;
		nst[tst].zero();
	}
}

int main() {
#ifdef LAEKOV_LOCAL
	freopen(".in", "r", stdin);
#endif

	scanf("%s", tmp);
	tst = 1;
	sst[1] = 1, nst[1].zero();
	for (char* i = tmp; *i; ++ i) {
		pushChar(*i);
	}
	while (sst[tst] == 0) {
		nst[tst - 1].mul(nst[tst]);
		-- tst;
	}
	BigInt ans;
	for (int i = 1; i <= tst; ++ i) {
		if (sst[i] == 1) {
			ans.add(nst[i]);
		}
	}
	for (int i = 1; i <= tst; ++ i) {
		if (sst[i] == -1) {
			ans.substract(nst[i]);
		}
	}
	ans.print();
}

