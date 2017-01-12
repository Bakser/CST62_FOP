
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n, pro, con1 = 0, con2 = 0, con3 = 0;
int cond[30] = {0};
long long ans = 0;
void DFS(int depth)
{
    if(depth == n)
    {ans++; return;}
    int con = (con1 | con2 | con3 | cond[depth]);
    con = con xor pro;
    //cout << depth <<" condition:"  << con << endl;
    while(con != 0)
    {
        int t1 = con1, t2 = con2, t3 = con3;
        int next = (con & (-con));
        con1 = (con1|next);
        con2 = ((con2|next) << 1)& pro;
        con3 = ((con3|next) >> 1)& pro;
        DFS(depth + 1);
        con -= next;
        con1 = t1;
        con2 = t2;
        con3 = t3;
    }
}
int main()
{
    int i, j;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            int x;
            x = 0;
            cond[i] += (1 << n-1-j) * x;
        }
    }
    pro = (1 << n) - 1;
    //cout<<pro;
    //for(i = 0; i < n; i++)
    //    cout << cond[i] <<endl;
    DFS(0);
    cout << ans;
    return 0;
}
