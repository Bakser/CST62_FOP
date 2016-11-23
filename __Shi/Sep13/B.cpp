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

int vis[1000], N, x;

int main(int argc, char *argv[])
{
	scanf("%d", &N);
	rep(i, 1, N)
	{
		int done = false;
		scanf("%d", &x);
		for (int j = 1; j <= 100; j += 5)
		{
			for (int k = j; k <= j + 4; ++k)
			{
				int flag = true;
				if (k + x - 1 > j + 4) break;
				for (int l = k; l <= k + x - 1; ++l)
					if (vis[l])
						flag = false;
				if (flag)
				{
					for (int l = k; l <= k + x - 1; ++l)
						vis[l] = true, printf("%d ", l);
					puts("");
					done = true;
					break;
				}
			}
			if (done) break;
		}
		if (!done)
		{
			rep(j, 1, x)
			{
				rep(k, 1, 100)
					if (!vis[k]) 
					{
						vis[k] = true, printf("%d ", k);
						break;
					}
			}
			puts("");
		}
	}
	return 0;
}
