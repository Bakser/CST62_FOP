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

int main(int argc, char *argv[])
{
	/*rep(A, 0, 9)
		rep(B, 0, 9)
			rep(C, 0, 9)
				rep(D, 0, 9)
				{
					int valid = true;
					valid &= D * 4 % 10 == A;
					int cur = D * 4 / 10;
					valid &= (C * 4 + cur) % 10 == B;
					cur = (C * 4 + cur) / 10;
					valid &= (B * 4 + cur) % 10 == C;
					cur = (B * 4 + cur) / 10;
					valid &= (A * 4 + cur) % 10 == D;
					if (valid) printf("%d%d%d%d\n", A, B, C, D);
				}*/
				
	puts("2178");
				
	return 0;
}
