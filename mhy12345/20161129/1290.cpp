#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1010
typedef long long qword;
char expr[MAXN];

qword solve(const char* expr,int l,int r)
{
		for (int i=r-1;i>=l;i--)
		{
				if (expr[i]=='+')
						return solve(expr,l,i)+solve(expr,i+1,r);
				if (expr[i]=='-')
						return solve(expr,l,i)-solve(expr,i+1,r);
		}
		for (int i=r-1;i>=l;i--)
		{
				if (expr[i]=='*')
						return solve(expr,l,i)*solve(expr,i+1,r);
		}
		qword ans=0;
		for (int i=l;i<r;i++)
				ans=ans*10+expr[i]-'0';
		return ans;
}

int main()
{
		scanf("%s",expr);
		printf("%lld\n",solve(expr,0,(int)strlen(expr)));
}
