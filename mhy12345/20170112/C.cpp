#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int stack[40],tops=-1;

int main()
{
		freopen("input.txt","r",stdin);
		int n,cnt=0;
		scanf("%d",&n);
		while (n)
		{
				if (n&1)stack[++tops]=cnt;
				n>>=1;
				cnt++;
		}
		while (~tops)
		{
				printf("2(%d)",stack[tops--]);
				if (~tops)
						printf("+");
		}
		printf("\n");
		return 0;
}
