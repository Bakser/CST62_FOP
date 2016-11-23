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

const int maxn = 500000;
int N, Q, cntx, cnty, best;
int hx[maxn], hy[maxn], L[maxn], R[maxn], M[maxn], y[maxn];
pii p[maxn], t[maxn * 4];
ll ans;

pii merge(pii a, pii b)
{
	if (a.xx == b.xx) return mp(a.xx, a.yy + b.yy);
	else return max(a, b);
}

void modify(int p, int L, int R, int x, int d)
{
	if (L == R)
	{
		t[p] = mp(d, 1);
		return;
	}
	int m = L + R >> 1;
	if (x <= m) 
		modify(p << 1, L, m, x, d);
	else
		modify(p << 1 | 1, m + 1, R, x, d);
	t[p] = merge(t[p << 1], t[p << 1 | 1]);
}

pii query(int p, int L, int R, int l, int r)
{
	if (L == l && R == r) return t[p];
	int m = L + R >> 1;
	if (r <= m) return query(p << 1, L, m, l, r);
	else if (l > m) return query(p << 1 | 1, m + 1, R, l, r);
	else return merge(query(p << 1, L, m, l, m), query(p << 1 | 1, m + 1, R, m + 1, r));
}

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin >> N >> Q;
	rep(i, 1, N) 
	{
		cin >> p[i].xx >> p[i].yy;
		hx[++cntx] = p[i].xx;
		hy[++cnty] = p[i].yy;
	}
	sort(hx + 1, hx + cntx + 1);
	sort(hy + 1, hy + cnty + 1);
	cntx = unique(hx + 1, hx + cntx + 1) - hx - 1;
	cnty = unique(hy + 1, hy + cnty + 1) - hy - 1;
	
	sort(p + 1, p + N + 1);
	rep(i, 1, N)
	{
		y[i] = lower_bound(hy + 1, hy + cnty + 1, p[i].yy) - hy;
		R[y[i]]++;
	}
	rep(i, 1, N)
	{
		int j = i;
		while (j <= N && p[i].xx == p[j].xx) ++j;
		rep(k, i, j - 1) 
		{
			R[y[k]]--;
			M[y[k]] = min(L[y[k]], R[y[k]]);
			modify(1, 1, cnty, y[k], M[y[k]]);
		}
		rep(k, i, j - 2)
		{
			int l = k - i + 1, r = j - k - 1;
			int cur = min(l, r);
			if (y[k] + 1 <= y[k + 1] - 1)
			{
				pii tmp = query(1, 1, cnty, y[k] + 1, y[k + 1] - 1);
				cur = min(cur, tmp.xx);
				if (cur > best)
				{
					best = cur;
					ans = tmp.yy;
				}
				else if (cur == best)
					ans += tmp.yy;
			}
		}
		rep(k, i, j - 1)
		{
			int l = k - i, r = j - k - 1;
			int cur = min(l, r);
			pii tmp = query(1, 1, cnty, y[k], y[k]);
			cur = min(cur, tmp.xx);
			if (cur > best)
			{
				best = cur;
				ans = tmp.yy;
			}
			else if (cur == best)
				ans += tmp.yy;
		}
		rep(k, i, j - 1) 
		{
			L[y[k]]++;
			M[y[k]] = min(L[y[k]], R[y[k]]);
			modify(1, 1, cnty, y[k], M[y[k]]);
		}		
		i = j - 1;
	}
	
	/*int Best = 0, Ans = 0;
	rep(i, 1, cntx)
		rep(j, 1, cnty)
		{
			int u = 0, d = 0, l = 0, r = 0;
			rep(k, 1, N)
			{
				if (p[k].yy == hy[j] && p[k].xx < hx[i]) ++l;
				if (p[k].yy == hy[j] && p[k].xx > hx[i]) ++r;
				if (p[k].xx == hx[i] && p[k].yy < hy[i]) ++u;
				if (p[k].xx == hx[i] && p[k].yy > hy[i]) ++d;
			}
			int cur = min(min(l, r), min(u, d));
			if (cur > Best) Best = cur, Ans = 1;
			else if (cur == Best) ++Ans;
		}
	if (Best == 0) Ans = 0;
	if (best == 0) ans = 0;
	cerr << Best << ' ' << best << endl;
	cerr << Ans << ' ' << ans << endl;
	assert(Best == best && ans == Ans);*/
	
	cout << ((Q == 1) ? best : ans) << endl;
	return 0;
}
