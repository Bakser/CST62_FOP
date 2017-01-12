#include <cstdio>
#include <algorithm>
using namespace std;
 
#define N 100010
int p[N];
bool np[N];
 
int main() {
	int num = 0;
	np[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!np[i])
			p[++num] = i;
		for (int j = 1; j <= num && i * p[j] <= N; ++j) {
			np[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;
		}
	}
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= num; ++i)
		if (p[i] > a && !np[p[i] - a]) {
			printf("%d %d", p[i], p[i] - a);
			break;
		}
	return 0;
}
