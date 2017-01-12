#include <cstdio>
int main() {
	for (int i = 0; i < 4; ++i) {
		if ((i == 0) + (i != 1) + (i == 1) + (i != 2) == 1)
			putchar('A' + i);
	}
	return 0;
}
