#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bool f[110];
int main() {
	int n, x;
	bool ok, emp;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		ok = 0;
		if (x <= 5) {
			for (int i = 1; i <= 20 && !ok; ++i) {
				for (int j = 1; j + x - 1 <= 5 && !ok; ++j) {
					emp = 1;
					for (int k = 0; k < x; ++k)
						if (f[j + k + (i - 1) * 5])
							emp = 0;
					if (emp) {
						for (int k = 0; k < x; ++k) {	
							f[j + k + (i - 1) * 5] = 1;
							if (k > 0)
								putchar(' ');
							printf("%d", j + k + (i - 1) * 5);
						}
						ok = 1;
					}
				}	
			}
		}
		
		if (!ok) {
			for (int i = 1; i <= 100 && x; ++i) {
				if (!f[i]) {
					f[i] = 1;
					--x;
					printf("%d", i);
					if (x)
						putchar(' ');
				}
			}
		}
		puts("");
	}
	return 0;
}
