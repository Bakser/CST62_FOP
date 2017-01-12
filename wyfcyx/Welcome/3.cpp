#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
char s[21];
struct Hero {
	int hp, num;
	pair<int, int> s[8];
	Hero() {
		hp = 30;
		num = 0;
		memset(s, 0, sizeof s);
	}
	void insert(int pos, pair<int, int> ss) {
		for (int i = num + 1; i >= pos + 1; --i)
			s[i] = s[i - 1];
		s[pos] = ss;
		++num;
	}
	void remove(int pos) {
		for (int i = pos; i < num; ++i)
			s[i] = s[i + 1];
		--num;
	}
}player[2];
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("tt.in.cpp", "r", stdin);
#endif
*/
	int n, a, b, c, o = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (s[0] == 's') {
			scanf("%d%d%d", &a, &b, &c);
			player[o].insert(a, make_pair(b, c));
		}
		else if (s[0] == 'a') {
			scanf("%d%d", &a, &b);
			if (b == 0) {
				player[o ^ 1].hp -= player[o].s[a].first;
			}
			else {
				player[o].s[a].second -= player[o ^ 1].s[b].first;
				player[o ^ 1].s[b].second -= player[o].s[a].first;
				if (player[o].s[a].second <= 0)
					player[o].remove(a);
				if (player[o ^ 1].s[b].second <= 0)
					player[o ^ 1].remove(b);
			}
		}
		else
			o ^= 1;
	}
	if (player[0].hp <= 0)
		puts("-1");
	else if (player[1].hp <= 0)
		puts("1");
	else
		puts("0");
	printf("%d\n", player[0].hp);
	printf("%d", player[0].num);
	for (int i = 1; i <= player[0].num; ++i)
		printf(" %d", player[0].s[i].second);
	puts("");
	printf("%d\n", player[1].hp);
	printf("%d", player[1].num);
	for (int i = 1; i <= player[1].num; ++i)
		printf(" %d", player[1].s[i].second);
	return 0;
}
