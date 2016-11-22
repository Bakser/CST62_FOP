#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
		freopen("input.txt","r",stdin);
		string s1,s2;
		cin>>s1>>s2;
		int x=1;
		for (int i=0;i<s1.length();i++)
				x=x*(s1[i]-'A'+1)%47;
		int y=1;
		for (int i=0;i<s2.length();i++)
				y=y*(s2[i]-'A'+1)%47;
		if (x==y)
				puts("GO");
		else
				puts("STAY");
}
