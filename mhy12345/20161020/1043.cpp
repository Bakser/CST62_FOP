#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int C(int x,int y)
{
		int res=1;
		for (int i=1;i<=x;i++)
				res*=i;
		for (int i=1;i<=y;i++)
				res/=i;
		for (int i=1;i<=x-y;i++)
				res/=i;
		return res;
}
int dp[20];

int main()
{
		int n;
		cin>>n;
		dp[0]=1;
		for (int i=1;i<=n;i++)
		{
				for (int j=0;j<i;j++)
						dp[i]+=dp[j]*C(i-1,i-1-j);
		}
		cout<<dp[n]<<endl;
		return 0;
}
