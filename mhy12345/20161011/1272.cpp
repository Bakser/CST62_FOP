#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 120
bool mp[MAXN][MAXN];

int main()
{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
				int x=i<n/2?n/2-1-i:i-n/2;
				for (int j=0;j<n;j++)
				{
						int y=j<n/2?n/2-1-j:j-n/2;
						printf("%c",max(x,y)%2?' ':'*');
				}
				printf("\n");
		}
}
