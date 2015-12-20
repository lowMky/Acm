/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月09日 星期五 17时26分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

struct Node{
    int x,y,dep;
    int cnt;
};
int vis[20][30][30];
int G[30][30];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m,k;

bool judge(Node a)
{
    if(a.cnt<=k&&1<=a.x&&a.x<=m&&1<=a.y&&a.y<=n&&!vis[a.cnt][a.y][a.x])
        return true;
    return false;
}

int bfs()
{
    Node s,tmp;
    s.x=s.y=1;
    s.cnt=s.dep=0;
    queue<Node> que;
    que.push(s);    
    while(!que.empty())
    {
        s=que.front();
        if(s.y==n&&s.x==m)
            return s.dep;
        que.pop();
        if(s.x==m&&s.y==n)
            return s.dep;
        for(int i=0;i<4;i++)
        {
            tmp.x=s.x+dx[i];
            tmp.y=s.y+dy[i];
            tmp.dep=s.dep+1;
            if(G[tmp.y][tmp.x])
                tmp.cnt=s.cnt+1;
            else
                tmp.cnt=0;
            if(judge(tmp))
            {
                vis[tmp.cnt][tmp.y][tmp.x]=true;
                que.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d",&k);
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&G[i][j]);
        printf("%d\n",bfs());
    }
    return 0;
}
