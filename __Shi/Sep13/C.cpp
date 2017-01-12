#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define pb(x) push_back(x)
#define mp(x, y) (make_pair(x, y))
#define clr(x) memset(x, 0, sizeof(x))
#define xx first
#define yy second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf = ~0U >> 1;
const ll INF = ~0ULL >> 1;
template <class T> inline void read(T &n)
{
    char c; int flag = 1;
    for (c = getchar(); !(c >= '0' && c <= '9' || c == '-'); c = getchar()); if (c == '-') flag = -1, n = 0; else n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0'; n *= flag;
}
//***************************

struct info
{
	int h, a;
	info(){}
	info(int _h, int _a) : h(_h), a(_a) {}
} hero[2][100];

int n;
char opt[100];

int main(int argc, char *argv[])
{
	scanf("%d", &n);
	hero[0][0] = hero[1][0] = info(30, 0);
	int cur = 0, winner = 0;
	rep(i, 1, n)
	{
		scanf("%s", opt);
		if (string(opt) == "summon")
		{
			int pos, attack, health;
			scanf("%d%d%d", &pos, &attack, &health);
			drep(j, 7, pos + 1) hero[cur][j] = hero[cur][j - 1];
			hero[cur][pos] = info(health, attack);
		}
		else if (string(opt) == "attack")
		{
			int attacker, defender;
			scanf("%d%d", &attacker, &defender);
			hero[cur][attacker].h -= hero[1 - cur][defender].a;
			hero[1 - cur][defender].h -= hero[cur][attacker].a;
			if (hero[cur][attacker].h <= 0)
			{
				rep(i, attacker, 7)
					hero[cur][i] = hero[cur][i + 1];
			}
			if (defender > 0 && hero[1 - cur][defender].h <= 0)
			{
				rep(i, defender, 7)
					hero[1 - cur][i] = hero[1 - cur][i + 1];
			}			
		}
		else cur = 1 - cur;
		if (hero[0][0].h <= 0) winner = -1;
		else if (hero[1][0].h <= 0) winner = 1;
	}
	printf("%d\n", winner);
	printf("%d\n", hero[0][0].h);
	int cnt = 0;
	rep(i, 1, 7) 
		if (hero[0][i].h > 0) cnt++;
	printf("%d ", cnt);
	rep(i, 1, cnt) printf("%d ", hero[0][i].h);
	puts("");
	printf("%d\n", hero[1][0].h);
	cnt = 0;
	rep(i, 1, 7) 
		if (hero[1][i].h > 0) cnt++;
	printf("%d ", cnt);
	rep(i, 1, cnt) printf("%d ", hero[1][i].h);
	puts("");
	return 0;
}
