#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<vector>
using namespace std;
#define MAXN 100000010
vector<int> lst;
bool is_prime(int x)
{
		if (x<=1)return false;
		for (int i=2;i*i<=x;i++)
				if (x%i==0)return false;
		return true;
}
int l,r;
char buf[20];
void check(int n)
{
		stringstream ss;
		for (int i=n-1;i>=0;i--)
				ss<<buf[i];
		for (int i=0;i<n;i++)
				ss<<buf[i];
		int x;
		ss>>x;
		if (x<=r && x>=l && is_prime(x))
				lst.push_back(x);
		ss.clear();

		for (int i=n-1;i>=0;i--)
				ss<<buf[i];
		for (int i=1;i<n;i++)
				ss<<buf[i];
		ss>>x;
		if (x<=r && x>=l && is_prime(x))
				lst.push_back(x);
		ss.clear();
}
void dfs(int now)
{
		if (now>4)return ;
		check(now);
		for (int i=0;i<10;i++)
		{
				buf[now]='0'+i;
				dfs(now+1);
				buf[now]='\0';
		}
}

int main()
{
		freopen("input.txt","r",stdin);
		scanf("%d%d",&l,&r);
		dfs(0);
		sort(lst.begin(),lst.end());
		lst.erase(unique(lst.begin(),lst.end()),lst.end());
		for (int i=0;i<lst.size();i++)
				printf("%d\n",lst[i]);
}
