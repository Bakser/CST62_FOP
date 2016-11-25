#include <cstdio>
int main() {
	for (int i = 0; i < 4; ++i) {
		if ((i != 0) + (i == 3) + (i == 1) + (i != 3) == 1)
			putchar('A' + i);
	}
	return 0;
}
