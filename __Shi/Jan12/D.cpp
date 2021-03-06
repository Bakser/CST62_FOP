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

int N, a[1000];

int main(int argc, char *argv[])
{
	scanf("%d", &N);
	rep(i, 1, N) scanf("%d", &a[i]);
	rep(i, 1, N)
	{
		int opt = i;
		rep(j, i + 1, N)
			if (a[j] < a[opt]) opt = j;
		printf("swap(a[%d], a[%d]):", i - 1, opt - 1);
		swap(a[i], a[opt]);
		rep(j, 1, N) printf("%d ", a[j]);
		puts("");
	}
	return 0;
}
