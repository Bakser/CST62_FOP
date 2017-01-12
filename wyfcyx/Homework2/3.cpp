#include <cstdio>
#include <algorithm>
using namespace std;
 
int a[3], r[3], b[3];
int main() {
	int i;
	for (i = 0; i < 3; ++i)
		a[i] = i;
	do {
		//printf("%d %d %d\n", a[0], a[1], a[2]);
		for (i = 0; i < 3; ++i)
			r[a[i]] = i;
		b[0] = r[1] > r[0];
		b[1] = (r[0] > r[1]) + (r[0] > r[2]);
		b[2] = (r[2] > r[1]) + (r[1] > r[0]);
		if (b[a[0]] > b[a[1]] && b[a[1]] > b[a[2]]) {
			printf("%c %c %c", 'A' + a[0], 'A' + a[1], 'A' + a[2]);
			//break;
		}
	}while (next_permutation(a, a + 3));
	return 0;
}
