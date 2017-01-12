#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 1010
int a[MAXN];
int n;
void solve(int* head,int* tail)
{
		if (head == tail)return ;
		int *bst = head;
		for (int *iter = head; iter != tail; iter++)
		{
				if (*bst > *iter)
						bst = iter;
		}
	//	while (head!=bst && *head<*bst)
	//			head++;
		swap(*head,*bst);
		printf("swap(a[%d], a[%d]):%d",(int)(head - a), int(bst - a),a[0]);
		for (int i=1;i<n;i++)
				printf(" %d",a[i]);
		printf("\n");
		solve(head+1,tail);

}

int main()
{
		freopen("input.txt","r",stdin);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
				scanf("%d",a+i);
		solve(a,a+n);
}
