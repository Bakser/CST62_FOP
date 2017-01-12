#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
//		freopen("input.txt","r",stdin);
		int n;
		int ans=0;
		scanf("%d",&n);
		for (register int i=3;i<=n;i++)
		{
				register double v=(double)n/i;
				if (n*2%i)continue;
				for (int j=1;j<=v;j++)
				{
						register int a = j;
						register int b = v*2-j;
						if (b==a || (b-a)%(i-1)!=0)continue;
						if ((a+b)*i/2 == n)
								ans++;
				}
		}
		cout<<ans;
}
