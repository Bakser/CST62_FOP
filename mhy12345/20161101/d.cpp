#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
#define MAXN 10100
string str[MAXN];

int main()
{
		//freopen("input.txt","r",stdin);
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
				cin>>str[i];
		sort(str,str+n);
		for (int i=0;i<n;i++)
				cout<<str[i]<<endl;
}
