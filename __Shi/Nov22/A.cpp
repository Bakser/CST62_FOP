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

string s1, s2;

int main(int argc, char *argv[])
{
	cin >> s1 >> s2;	
	int f1 = 1, f2 = 1;
	REP(i, 0, s1.size()) 
		f1 = f1 * (s1[i] - 'A' + 1) % 47;
	REP(i, 0, s2.size())
		f2 = f2 * (s2[i] - 'A' + 1) % 47;
	puts(f1 == f2 ? "GO" : "STAY");
	return 0;
}
