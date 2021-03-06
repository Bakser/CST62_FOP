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

int N, x[100], y[100];

int main(int argc, char *argv[])
{
	scanf("%d", &N);
	rep(i, 1, 3) scanf("%d%d", &x[i], &y[i]);
	
	rep(k, 1, 3)
	{
		int cnt = 0;
		rep(i, 1, 3)
		{
			if (x[i] == k)
			{
				if (!y[i]) ++cnt;
			}
			else if (y[i]) ++cnt;
		}
		if (cnt == N)
			cout << k << endl;
	}
	return 0;
}
