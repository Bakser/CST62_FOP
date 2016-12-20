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

int a, b;
set<int> ans;

int isprime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

void append(string x)
{
	int y = stoi(x);
	if (y >= a && y <= b && isprime(y))
		ans.insert(y);
}

int main(int argc, char *argv[])
{
	cin >> a >> b;
	for (int i = 1; i < 10000; ++i)
	{
		string x = to_string(i);
		string y = x;
		reverse(y.begin(), y.end());
		append(x + y);
		y = "";
		for (int j = 0; j + 1 < x.size(); ++j)
			y += x[j];
		reverse(y.begin(), y.end());
		append(x + y);
	}
	for (auto x:ans) cout << x << endl;
	return 0;
}
