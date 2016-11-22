#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;

int main()
{
		scanf("%d",&n);
		for (int i=-n+1;i<=n-1;i++)
		{
				for (int j=-n+1;j<=n-1;j++)
						printf("%c ",!i || !j || abs(i)==abs(j)?'A'+n-1-max(abs(j),abs(i)):'.');
				printf("\n");
		}
}
