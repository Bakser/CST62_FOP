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

// x*n+n*(n-1)/2*d=S

int S, ans;

int main(int argc, char *argv[])
{
	cin >> S;
	for (int n = 3; n * (n - 1) / 2 <= S; ++n)
		if (S * 2 % n == 0)
		{
			for (int x = 1; x * n + n * (n - 1) / 2 <= S; ++x)
			{
				int d = (S - x * n) * 2 / n / (n - 1);
				if (d > 0 && x * n + n * (n - 1) / 2 * d == S)
					ans++;
			}
		}
	
	cout << ans << endl;
	return 0;
}
