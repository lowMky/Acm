/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月13日 星期二 20时09分40秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
struct Cyc{
    int r,x,y;
}cyc[1100];

int n;
vector<int> G[1100];
vector<int> th;
bool vis[1100];
double ans1,ans2;
bool dfs(int u)
{
    vis[u]=true;
    if(cyc[u].x<=cyc[u].r)
        ans1=min(ans1,cyc[u].y-sqrt(cyc[u].r*cyc[u].r-cyc[u].x*cyc[u].x));
    if(cyc[u].x+cyc[u].r>=1000)
        ans2=min(ans2,cyc[u].y-sqrt(cyc[u].r*cyc[u].r-(1000.0-cyc[u].x)*(1000.0-cyc[u].x))); 
    if(cyc[u].y<=cyc[u].r)
        return false;
    for(int i=0;i<G[u].size();i++)
        if(!vis[G[u][i]]&&!dfs(G[u][i]))
            return false;
    return true;
}

bool judge(Cyc a,Cyc b)
{
    if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=(a.r+b.r)*(a.r+b.r))
        return true;
    return false;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        for(int i=0;i<1100;i++)
            G[i].clear();
        th.clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&cyc[i].x,&cyc[i].y,&cyc[i].r);
            if(cyc[i].y+cyc[i].r>=1000)
                th.push_back(i);

            for(int j=0;j<i;j++)
                if(judge(cyc[i],cyc[j]))
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
        }
        ans1=ans2=1000.0;
        for(int i=0;i<th.size();i++)
            if(!vis[th[i]]&&!dfs(th[i]))
            {
                flag=1;
                break;
            }
        if(flag)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("%.2f %.2f %.2f %.2f\n",0.0,ans1,1000.0,ans2);
    }
    return 0;
}
