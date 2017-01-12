#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 1010
const int mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool check(int x,int y,int n)
{
		if (x>=n/2)x=n-1-x;
		if (y>=n/2)y=n-1-y;
		return x==y;
}

bool vis[MAXN][MAXN];
bool valid(int x,int y,int n)
{
		return x>=0 && y>=0 && x<n && y<n && !vis[x][y];
}

int main()
{
		freopen("input.txt","r",stdin);
		int n;
		int dx,dy;
		dx=dy=0;
		scanf("%d",&n);
		int ans=0;
		int dir=0;
		vis[0][0]=true;
		for (int i=0;i<n;i++)
		{
				for (int j=0;j<n;j++)
				{
						int v;
						scanf("%d",&v);
						if (check(dx,dy,n))
						{
								ans+=v;
						}
				//		printf("%d %d %d\n",dx,dy,v);
						if (i==n-1 && j==n-1)break;
						while (!valid(dx+mov[dir][0],dy+mov[dir][1],n))
								dir = (dir+1)%4;
						dx+=mov[dir][0];
						dy+=mov[dir][1];
						vis[dx][dy]=true;
				}
		}
		printf("%d\n",ans);
}
