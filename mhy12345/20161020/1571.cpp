#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 1010000
int dp[MAXN];

int main()
{
		int n,a,b;
		cin>>n>>a>>b;
		dp[0]=1;
		for (int i=1;i<=n;i++)
		{
				if (i>=a)dp[i]+=dp[i-a];
				if (i>=b)dp[i]+=dp[i-b];
		}
		printf("%d\n",dp[n]);
}
