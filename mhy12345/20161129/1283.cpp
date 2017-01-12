#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 15
int status[MAXN];
int n;
int cnt;
void dfs(int now,int sm,int sl,int sr)
{
		if (now==n)
		{
				cnt++;
				return ;
		}
		int jn = sm | sl | sr | status[now];
		for (int i=0;i<n;i++)
		{
				if (jn&(1<<i))continue;
				dfs(now+1,sm|(1<<i),(sl|(1<<i))<<1,(sr|(1<<i))>>1);
		}
}

int main()
{
	//	freopen("input.txt","r",stdin);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
				for (int j=0;j<n;j++)
				{
						int x;
						scanf("%d",&x);
						status[i]=status[i]*2+x;
				}
		}
		dfs(0,0,0,0);
		printf("%d\n",cnt);
}
