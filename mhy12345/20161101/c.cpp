#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 10100
int a[MAXN],b[MAXN],c[MAXN],seq[MAXN];
int s[MAXN];
bool cmp_seq(int x,int y)
{
		if (s[x]!=s[y])return s[x]>s[y];
		if (a[x]!=a[y])return a[x]>a[y];
		if (b[x]!=b[y])return b[x]>b[y];
		return x<y;
}

int main()
{
		//freopen("input.txt","r",stdin);
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
				scanf("%d %d %d",a+i,b+i,c+i),s[i]=a[i]+b[i]+c[i],seq[i]=i;
		sort(seq,seq+n,cmp_seq);
		for (int i=0;i<n;i++)
				printf("%d %d %d %d\n",a[seq[i]],b[seq[i]],c[seq[i]],seq[i]+1);
}
