#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
		for (int a=0;a<10;a++)
		for (int b=0;b<10;b++)
		for (int c=0;c<10;c++)
		for (int d=0;d<10;d++)
		{
				if (a==b || a==c || a==d || b==c || b==d || c==d)continue;
				int v1=1000*a+100*b+10*c+d;
				int v2=1000*d+100*c+10*b+a;
				if (v1*4==v2)
				{
						cout<<v1<<endl;
				}
		}
}
