#include <cstdio>

int getHash() {
	char a[103];
	scanf("%s", a);
	int s(1);
	for (int i = 0; a[i]; ++ i) {
		s = s * (a[i] - 64) % 47;
	}
	return s;
}

int main() {
	puts(getHash() == getHash() ? "GO" : "STAY");
}	
