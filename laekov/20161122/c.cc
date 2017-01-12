#include <cstdio>
#include <cstring>

const int maxn = 100003;

int prm[maxn];

void pre() {
	memset(prm, 0, sizeof(prm));
	for (int i = 2; i < maxn; ++ i) {
		for (int j = i * 2; j < maxn; j += i) {
			prm[j] = 1;
		}
	}
}

int main() {
	pre();
	int s;
	scanf("%d", &s);
	for (int i = 2; 1; ++ i) {
		if (!prm[i] && !prm[i + s]) {
			printf("%d %d\n", i + s, i);
			break;
		}
	}
}
