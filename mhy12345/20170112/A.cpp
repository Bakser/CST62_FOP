#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
		freopen("input.txt","r",stdin);
		int n;
		scanf("%d",&n);
		int l=1;
		int ans=0;
		for (int i=0;i<n;i++)l*=10;
		for (int i=l/10;i<l;i++)
		{
				int x=i;
				int s=0;
				while (x)
				{
						if (x%10==3)s++;
						x/=10;
				}
				if (s%2==0)
						ans++;
		}
		printf("%d\n",ans);
}
