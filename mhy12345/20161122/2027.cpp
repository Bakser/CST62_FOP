#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1000000
int a[MAXN];

int main()
{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
				scanf("%d",a+i);
		sort(a,a+n);
		if (n%2==1)
				printf("%d.00\n",a[n/2]);
		else
				printf("%.2lf\n",(a[n/2]+a[n/2-1])/2.0);
}
