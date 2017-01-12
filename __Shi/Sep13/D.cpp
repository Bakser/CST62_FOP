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

const int maxn = 200000;

int n, m, ans, x, y, c, vis[maxn], dis[maxn];
pii pre[maxn];
vector<pii> E[maxn];
queue<int> Q;

int main(int argc, char *argv[])
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d%d", &x, &y, &c), E[x].pb(mp(y, c)), E[y].pb(mp(x, c));
	Q.push(1); vis[1] = true;
	rep(i, 2, n) dis[i] = inf;
	while (Q.size())
	{
		int u = Q.front(); Q.pop(); vis[u] = false;
		REP(i, 0, E[u].size())
			if (dis[u] + E[u][i].yy < dis[E[u][i].xx]
			|| dis[u] + E[u][i].yy == dis[E[u][i].xx] && E[u][i].yy < pre[E[u][i].xx].yy)
			{
				dis[E[u][i].xx] = dis[u] + E[u][i].yy;
				pre[E[u][i].xx] = mp(u, E[u][i].yy);
				if (!vis[E[u][i].xx])
					vis[E[u][i].xx] = true, Q.push(E[u][i].xx);
			}
	}
	rep(i, 2, n) ans += pre[i].yy;
	printf("%d\n", ans);
	return 0;
}
