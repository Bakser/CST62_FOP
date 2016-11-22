#include<iostream>
#include<cstdio>
#include<algorithm>
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
int main()
{
		int n;
		cin>>n;
		for (int i=0;i<=n-1;i++)
		{
				for (int j=0;j<=i;j++)
				{
						cout<<C(i,j)<<" ";
				}
				cout<<endl;
		}
}
