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

int n, a[1000], b[1000], c[1000], ans;

int main(int argc, char *argv[])
{
	cin >> n;
	rep(i, 1, 3) cin >> a[i];
	rep(i, 1, 3) cin >> b[i];
	for (c[1] = 1; c[1] <= n; ++c[1])
		for (c[2] = 1; c[2] <= n; ++c[2])
			for (c[3] = 1; c[3] <= n; ++c[3])
			{
				int flag = false;
				
				int cur = true;
				rep(k, 1, 3)
					if (!(abs(a[k] - c[k]) <= 2 || n - abs(a[k] - c[k]) <= 2)) cur = false;
				flag |= cur;
				
				
				cur = true;
				rep(k, 1, 3)
					if (!(abs(b[k] - c[k]) <= 2 || n - abs(b[k] - c[k]) <= 2)) cur = false;
				flag |= cur;
				
				ans += flag;				

			}
			
	cout << ans << endl;
	return 0;
}
