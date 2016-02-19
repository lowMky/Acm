/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月01日 星期四 12时07分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
struct Edge{
    int v,nex;
}edge[10010];
int head[110];
int tot,flag;
bool vis[110];
vector<int> ans;
void addedge(int u,int v)
{
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

void dfs(int u)
{
    if(flag)
        return;
    vis[u]=-1;
    for(int i=head[u];i!=-1;i=edge[i].nex)
        if(vis[edge[i].v]==-1)
        {
            flag=1;
            break;
        }
        else if(!vis[edge[i].v])
            dfs(edge[i].v);
    ans.push_back(u);
    vis[u]=1;
}
void init()
{
    tot=flag=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    ans.clear();
}
int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(v,u);
        }
        for(int i=1;i<=n;i++)
            if(!vis[i])
                dfs(i);
        for(int i=0;i<ans.size();i++)
        {
            printf("%d",ans[i]);
            if(i<ans.size()-1)
                printf(" ");
            else
                printf("\n");
        } 
    }
    return 0;
}
