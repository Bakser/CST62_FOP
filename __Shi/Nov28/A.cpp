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

char s[1000];
int len, ans;

int main(int argc, char *argv[])
{
	scanf("%s", s);
	len = strlen(s);
	int cur = 1;
	REP(i, 0, len)
		if (s[i] == '+') cur = 1;
		else if (s[i] == '-') cur = -1;
		else
		{
			int m = 1, c = 0;
			int j = i;
			while (j < len && (s[j] >= '0' && s[j] <= '9') || s[j] == '*')
			{
				if (s[j] >= '0' && s[j] <= '9') c = c * 10 + s[j] - '0';
				else m *= c, c = 0;
				++j;
			}
			i = j - 1;
			m *= c;
			ans += cur * m;
		}
	printf("%d\n", ans);
	return 0;
}
