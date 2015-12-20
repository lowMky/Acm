/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月01日 星期四 15时04分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct Edge{
    int v,nex;
    int w;
}edge[401000];
int tot;
int head[100100];
int n,m;
bool vis[100100];
int dist[100100];
int ans[100100];
queue<int> que;
void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

void bfs()
{
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(n);
    dist[n]=0;
    vis[n]=true;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        if(u==1)
            break;
        for(int i=head[u];i!=-1;i=edge[i].nex)
            if(!vis[edge[i].v])
            {
                vis[edge[i].v]=true;
                que.push(edge[i].v);
                dist[edge[i].v]=dist[u]+1;
            }
    }
}

void bfs2()
{
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(1);
    vis[1]=true;
    while(!que.empty())
    {   
        if(vis[n])
            break;
        int tmp=-1;
        vector<int> to;
        int u;
        while(!que.empty())
        {
            u=que.front();
            to.push_back(u);
            que.pop();
            for(int j=head[u];j!=-1;j=edge[j].nex)
            {
                int v=edge[j].v;
                if(vis[v]||dist[v]!=dist[u]-1)
                    continue;
                if(tmp==-1||edge[j].w<tmp)
                    tmp=edge[j].w;
            }
        }
        ans[dist[1]-dist[u]]=tmp;
        int cnt=to.size();
        for(int i=0;i<cnt;i++)
        {
            int u=to[i];
            for(int j=head[u];j!=-1;j=edge[j].nex)
            {
                int v=edge[j].v;
                if(vis[v]||dist[v]!=dist[u]-1)
                    continue;
                if(edge[j].w==tmp)
                {
                    que.push(v);
                    vis[v]=true;
                }
            }
        }
    }   
}

void init()
{
    tot=0;
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
        head[i]=-1;
    }   
}
int main()
{
    int u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while(m--)
        {
            cin>>u>>v>>w;
            if(u==v)
                continue;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        bfs();
        bfs2();
        cout<<dist[1]<<endl;
        for(int i=0;i<dist[1];i++)
        {
            cout<<ans[i];
            if(i<dist[1]-1)
                cout<<" ";
            else
                cout<<endl;
        }   
    }
    return 0;
}

