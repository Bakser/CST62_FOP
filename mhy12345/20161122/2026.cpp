#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool is_prime(int x)
{
		for (int i=2;i*i<=x;i++)
				if (x%i==0)return false;
		return true;
}


int main()
{
		int n;
		scanf("%d",&n);
		for (int i=n+2;;i++)
		{
				if (is_prime(i) && is_prime(i-n))
				{
						printf("%d %d\n",i,i-n);
						return 0;
				}
		}
}
