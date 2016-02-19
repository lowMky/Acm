/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 14时58分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
vector<int> G[maxn];
int pos[maxn];

int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&t),pos[t]=i,G[i].clear();
        int root;
        scanf("%d",&root);
        stack<int> sta;
        sta.push(root);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&t);
            while(1)
            {
                int u=sta.top();
                if(pos[u]+1<pos[t]||(pos[u]+1==pos[t]&&u>t)||u==root)
                {
                    G[u].push_back(t);
                    sta.push(t);
                    break;
                }
                else
                    sta.pop();
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d:",i);
            for(int j=0,sz=G[i].size();j<sz;j++)
                printf(" %d",G[i][j]);
            puts("");
        }
    }
    return 0;
}
