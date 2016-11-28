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

int G[100][100], a[100], b[100], p[100], ans, N;

int main(int argc, char *argv[])
{
	cin >> N;
	rep(i, 1, N) rep(j, 1, N) cin >> G[i][j];
	rep(i, 1, N) p[i] = i;
	do
	{
		rep(i, 1, 2 * N) a[i] = b[i] = 0;
		int valid = true;
		rep(i, 1, N) 
		{
			if (G[i][p[i]] || a[i + p[i]] || b[i - p[i] + N]) valid = false;
			a[i + p[i]] = b[i - p[i] + N] = true;
		}
		ans += valid;
	} while (next_permutation(p + 1, p + N + 1));
	cout << ans << endl;
	return 0;
}
