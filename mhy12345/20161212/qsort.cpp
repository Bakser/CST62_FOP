#include<iostream>
using namespace std;

void qsort(int a[],int l,int r)
{
		if (l+1>=r)return ;
		swap(a[l],a[(l+r)/2]);
		int p=l+1,q=r-1;
		while (p-1<q)
		{
				while (a[p]<a[l])p++;
				while (p-1<q && a[q]>=a[l])q--;
				if (p-1<q)swap(a[p],a[q]);
		}
		for (int i=l;i<r;i++)
				printf("%d ",a[i]);
		printf("\n");
		qsort(a,l,p);
		qsort(a,p,r);
}

int main()
{
		srand(time(0));
		int n=10;
		int a[n];
		for (int i=0;i<n;i++)
				a[i]=rand()%12;
		qsort(a,0,10);
		for (int i=0;i<n;i++)
				printf("%d ",a[i]);
}
