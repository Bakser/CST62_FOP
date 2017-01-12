#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
bool isprime(int x)
{
		for (int i=2;i*i<=x;i++)
				if (x%i==0)
						return false;
		return true;
}

int main()
{
		//freopen("input.txt","r",stdin);
		int n;
		vector<int> v1,v2;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
				int x;
				scanf("%d",&x);
				if (isprime(x))
						v1.push_back(x);
				else
						v2.push_back(x);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		v1.erase(unique(v1.begin(),v1.end()),v1.end());
		v2.erase(unique(v2.begin(),v2.end()),v2.end());
		for (int i=v2.size()-1;i>=0;i--)
				printf("%d ",v2[i]);
		printf("\n");
		for (int i=0;i<v1.size();i++)
				printf("%d ",v1[i]);
		printf("\n");
}
