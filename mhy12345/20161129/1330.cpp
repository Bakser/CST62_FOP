#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int p;
struct matrix
{
		int a[2][2];
		matrix()
		{
				memset(a,0,sizeof(a));
		}
		void eye()
		{
				a[0][0]=a[1][1]=1%p;
				a[1][0]=a[0][1]=0;
		}
		void read()
		{
				for (int i=0;i<2;i++)
						for (int j=0;j<2;j++)
								scanf("%d",&a[i][j]),a[i][j]%=p;
		}
		void print()
		{
				for (int i=0;i<2;i++)
				{
						for (int j=0;j<2;j++)
						{
								printf("%d ",a[i][j]);
						}
						printf("\n");
				}
				printf("\n");
		}
};
matrix operator * (matrix m1,matrix m2)
{
		matrix res;
		for (int i=0;i<2;i++)
				for (int j=0;j<2;j++)
						for (int k=0;k<2;k++)
								res.a[i][j] = (res.a[i][j] + m1.a[i][k]*m2.a[k][j])%p;
		return res;
}

matrix pow_mod(matrix x,int n)
{
		matrix res;
		res.eye();
		while (n)
		{
				if (n&1)
						res=res*x;
				x=x*x;
				n>>=1;
		}
		return res;
}

int main()
{
//		freopen("input.txt","r",stdin);
		int n;
		scanf("%d%d",&n,&p);
		matrix a;
		a.read();
		pow_mod(a,n).print();
}
