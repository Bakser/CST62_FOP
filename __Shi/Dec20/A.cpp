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

int K, len;
char s[10000];

int main(int argc, char *argv[])
{
	scanf("%d%s", &K, s);
	len = strlen(s);
	if (K == 1)
	{
		REP(i, 0, len)
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 'a' + 'A';
	}
	else if (K == 2)
	{
		REP(i, 0, len)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';		
	}
	else if (K == 3)
		reverse(s, s + len);
	else if (K == 4)
	{
		REP(i, 0, len)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';	
			else
				s[i] = s[i] - 'a' + 'A';	
	}
	if (K < 5)
	{
		cout << s << endl;
	}
	else 
	{
		REP(i, 0, len)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';	
		REP(i, 0, len)
		{
			int j = i + 1;
			while (j < len && s[j] == s[j - 1] + 1) ++j;
			if (j - i > 2)
			{
				putchar(s[i]);
				putchar('-');
				putchar(s[j - 1]);
				i = j - 1;
			}
			else putchar(s[i]);
		}
	}
	return 0;
}
