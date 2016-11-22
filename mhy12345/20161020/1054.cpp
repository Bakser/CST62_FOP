#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 1010000
int dp[MAXN];
int prime[MAXN],topp=-1;
bool pflag[MAXN];
int mprime[MAXN];

void init()
{
		for (int i=2;i<MAXN;i++)
		{
				if (!pflag[i])
				{
						prime[++topp]=i;
						mprime[i]=i;
				}
				for (int j=0;j<=topp && i*prime[j]<MAXN;j++)
				{
						pflag[i*prime[j]]=true;
						mprime[i*prime[j]]=prime[j];
						if (i%prime[j]==0)break;
				}
		}
}

int main()
{
		int n,p;
		scanf("%d%d",&n,&p);
		init();
		dp[0]=1;
		for (int i=1;i<=n;i++)
		{
				vector<int> fact;
				int x=i;
				vector<int> lst;
				lst.push_back(1);
				while (x>1)
				{
						int t=mprime[x];
						for (int j=lst.size()-1;j>=0;j--)
								lst.push_back(lst[j]*t);
						x/=t;
				}
				sort(lst.begin(),lst.end());
				lst.erase(unique(lst.begin(),lst.end()),lst.end());
				for (int j=0;j<lst.size();j++)
						dp[i]=(dp[i]+dp[i-lst[j]])%p;
		}
		printf("%d\n",dp[n]);
}
