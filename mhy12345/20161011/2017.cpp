#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;


int get_days(int m,int n)
{
		int days;
		switch(n)
		{
				case 2:
						days=m%4?28:(m%100?29:(m%400?28:29));break;
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:
						days=31;break;
				default:
						days=30;break;
		}
		return days;
}
int main()
{
	//	freopen("input.txt","r",stdin);
		int n,m;
		time_t tt;
		tm tmm;
		scanf("%d%d",&m,&n);
		int fst=5;
		for (int i=0;i<=m;i++)
		{
				for (int j=1;j<=12;j++)
				{
						if (i==m && j==n)break;
						fst=(fst+get_days(i,j))%7;
				}
		}
		int days=get_days(m,n);
		cout<<"MON\t"
				<<"TUE\t"
				<<"WED\t"
				<<"THU\t"
				<<"FRI\t"
				<<"SAT\t"
				<<"SUN\n";
		for (int i=0;i<fst;i++)
				cout<<"\t";
		for (int i=0;i<days;i++)
		{
				cout<<i+1;
				fst=(fst+1)%7;
				if (fst)
						cout<<"\t";
				else
						cout<<"\n";
		}
}
