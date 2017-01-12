#include <cstdio>
#include <cstring>
int f(char *s) {
	int n = strlen(s), a = 1;
	for (int i = 0; i < n; ++i)
		a *= (s[i] - 'A' + 1);
	return a % 47;
}
int main() {
	char s1[6], s2[6];
	scanf("%s%s", s1, s2);
	if (f(s1) == f(s2))
		puts("GO");
	else
		puts("STAY");
	return 0;
}
