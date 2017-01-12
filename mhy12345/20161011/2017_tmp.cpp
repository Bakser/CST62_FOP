#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;


int main()
{
	//	freopen("input.txt","r",stdin);
		int n,m;
		time_t tt;
		tm tmm;
		scanf("%d%d",&m,&n);
		tmm.tm_year=m-1900;
		tmm.tm_mon=n-1;
		tmm.tm_mday=1;
		tmm.tm_hour=tmm.tm_min=tmm.tm_sec=0;
		tt=mktime(&tmm);
		int fst=(tt/86400+4)%7;
	//	cout<<fst<<endl;
		int days;
		switch(n)
		{
				case 2:
						days=m%4?28:m%100?m%400?29:28:29;break;
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:
						days=31;break;
				default:
						days=30;break;
		}
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
