#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long qword;

qword fib(int x)
{
		if (x<=1)return 1;
		return fib(x-1)+fib(x-2);
}

int main()
{
		int n;
		while (~scanf("%d",&n))
				printf("%lld\n",fib(n));
}
