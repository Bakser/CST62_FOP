#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
		int n;
		int ans=0;
		scanf("%d",&n);
		for (int i=3;i<=n;i++)
		{
				if (i%2==1)
				{
						if (n%i == 0)
						{
								int a = n/i;
								ans+=(a-1)/(i/2);
						}
				}else if (i%2==0)
				{
						if (n*2%i==0)
						{
								if (n%i==0)
								{
										int a=n/i;
										ans+=(a-1)/(i/2);
								}else
								{
										int a=n/i;
										ans+=a/(i/2);
								}
						}
				}
		}
		cout<<ans<<endl;
}
