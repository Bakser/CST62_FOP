#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3][2];

int main()
{
		int n;
		scanf("%d",&n);
		for (int i=0;i<3;i++)
				scanf("%d%d",&a[i][0],&a[i][1]),a[i][0]--;
		for (int i=0;i<3;i++)
		{
				int s=0;
				for (int j=0;j<3;j++)
						if ((a[j][0]==i) != a[j][1])
								s++;
				if (s==n)
						printf("%d\n",i+1);
		}
		return 0;
}
