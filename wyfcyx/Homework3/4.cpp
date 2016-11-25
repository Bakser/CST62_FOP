#include <cstdio>
 
int check(int x) {
	if (x % 400 == 0)
		return 366;
	else if (x % 100 == 0)
		return 365;
	else if (x % 4 == 0)
		return 366;
	else
		return 365;
}
 
static int dd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
int main() {
	int d = 3, m = 0, y = 1970;
	int a, b;
	scanf("%d%d", &a, &b);
	while (y < a)
		(d += check(y++)) %= 7;
	while (y > a)
		d = ((d - check(--y)) % 7 + 7) % 7;
	dd[1] += (check(a) == 366);
	--b;
	while (m < b)
		(d += dd[m++]) %= 7;
	//printf("%d\n", d);
	printf("MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\n");
	int day = 1;
	while (dd[b] > 0) {
		for (int i = 0; i < 7; ++i) {
			if (i >= d && dd[b] > 0) {
				printf("%d", day++);
				--dd[b];
			}
			printf("\t");
		}
		d = 0;
		if (dd[b] > 0)
			puts("");
	}
	return 0;
}
