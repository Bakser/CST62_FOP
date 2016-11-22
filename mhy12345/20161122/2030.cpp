#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1100
#define INF 0x3f3f3f3f//很大的一个数
int a[MAXN][MAXN];
int dp[MAXN][MAXN];//dp[i][j]表示走到(i,j)位置的最大路径和

int main()
{
		//freopen("input.txt","r",stdin);
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
				for (int j=1;j<=i;j++)
						scanf("%d",&a[i][j]);
		for (int i=0;i<MAXN;i++)
				for (int j=0;j<MAXN;j++)
						dp[i][j]=-INF;
		dp[1][1]=a[1][1];
		int ans=a[1][1];
		for (int i=2;i<=n;i++)
				for (int j=1;j<=i;j++)
						dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j],ans=max(ans,dp[i][j]);
		//dp[i][j]的值只与dp[i-1][j-1],dp[i-1][j]有关
		printf("%d\n",ans);
}
