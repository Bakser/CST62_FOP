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

int mo, c[85][85];
const int N = 2;
ll B;

struct matrix
{
	int a[85][85];
	
	void operator *= (matrix b)
	{
		memcpy(c, a, sizeof(c));
		memset(a, 0, sizeof(a));
		REP(i, 0, N)
			REP(j, 0, N)
				REP(k, 0, N)
					a[i][j] = (a[i][j] + (ll) c[i][k] * b.a[k][j]) % mo;
	}
	
} trans, ans, Tmp; 


matrix Pow(matrix base, ll n)
{
	int flag = 0;
	matrix ans, tmp;
	while (n)
	{
		if (n & 1) 
		{
			if (!flag) flag = 1, ans = base;
			else ans *= base;
		}
		base *= base;
		n >>= 1;
	}
	return ans;
}


int main(int argc, char *argv[])
{
	matrix A;
	cin >> B >> mo;
	if (B == 0)
	{
		cout << 1 % mo << " 0" << endl;
		cout << "0 " << 1 % mo << endl;
		return 0;
	}
	REP(i, 0, 2) REP(j, 0, 2) cin >> A.a[i][j];
	A = Pow(A, B);
	REP(i, 0, 2)
	{
		REP(j, 0, 2) cout << A.a[i][j] % mo << ' ';
		cout << endl;
	}
	return 0;
}
