#include <cstdio>
#include <cstring>
#include <algorithm>
 
int p[10];
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		p[i] = i;
	do {
		bool ok = 1;
		for (int i = 0; i < n; ++i)
			if (p[i] == i)
				ok = 0;
		ans += ok;
	}
	while (std::next_permutation(p, p + n));
	printf("%d", ans);
	return 0;
} 
