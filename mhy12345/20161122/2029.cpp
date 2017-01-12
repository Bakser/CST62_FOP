#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;

int dis(int a,int b)//两个位置在环上的距离
{
		if (a>b)swap(a,b);
		return min(b-a,a+n-b);
}

int main()
{
		//freopen("input.txt","r",stdin);
		scanf("%d",&n);
		int a[3],b[3];
		for (int i=0;i<3;i++)
				scanf("%d",&a[i]);
		for (int i=0;i<3;i++)
				scanf("%d",&b[i]);
		int cnt=0;
		for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
						for (int k=1;k<=n;k++)
						{
								bool flag=false;
								if (dis(i,a[0])<=2 && dis(j,a[1])<=2 && dis(k,a[2])<=2)
										flag=true;
								if (dis(i,b[0])<=2 && dis(j,b[1])<=2 && dis(k,b[2])<=2)
										flag=true;
								cnt+=flag;
						}
		printf("%d\n",cnt);
}
