#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20];

int main()
{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
				a[i]=i;
		int s=0;
		do{
				bool flag=false;
				for (int i=0;i<n;i++)
						if (a[i]==i)flag=true;
				if (!flag)s++;
		}while (next_permutation(a,a+n));
		printf("%d\n",s);
}
