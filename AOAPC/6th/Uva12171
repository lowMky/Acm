/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月20日 星期二 17时44分02秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll V,S;
int G[110][110][110];
bool vis[110][110][110];
int id[3][1100];
vector<int> loc[3];
set<int> loct[3];
int sz[3];
int dz[]={-1,0,0,1,0,0};
int dy[]={0,-1,0,0,1,0};
int dx[]={0,0,-1,0,0,1};

struct Box{
    int xl,xr;
    int yl,yr;
    int zl,zr;
    void read()
    {
        int xlen,ylen,zlen;
        scanf("%d%d%d",&xl,&yl,&zl);
        scanf("%d%d%d",&xlen,&ylen,&zlen);
        xr=xl+xlen;
        yr=yl+ylen;
        zr=zl+zlen;
        loct[0].insert(xl);
        loct[0].insert(xr);
        loct[1].insert(yl);
        loct[1].insert(yr);
        loct[2].insert(zl);
        loct[2].insert(zr);
    }
    void print()
    {
        printf("%d %d %d %d %d %d\n",xl,xr,yl,yr,zl,zr);
    }
}box[55];

struct Node{
    int x,y,z;
};

ll fun_S(int i,int j,int k,int flag)
{
    ll h=loc[2][i+1]-loc[2][i];
    ll w=loc[1][j+1]-loc[1][j];
    ll l=loc[0][k+1]-loc[0][k];
    if(flag%3==0)
        return l*w;
    else if(flag%3==1)
        return h*l;
    else 
        return h*w;
}

ll fun_V(int i,int j,int k)
{
    ll h=loc[2][i+1]-loc[2][i];
    ll w=loc[1][j+1]-loc[1][j];
    ll l=loc[0][k+1]-loc[0][k];
    return h*w*l;
}

void bfs()
{
    Node s,tmp;
    s.x=s.y=s.z=0;
    queue<Node> que;
    que.push(s);
    vis[0][0][0]=true;
    while(!que.empty())
    {
        s=que.front();
        que.pop();
        V+=fun_V(s.z,s.y,s.x);
        for(int i=0;i<6;i++)
        {
            tmp.x=s.x+dx[i];
            tmp.y=s.y+dy[i];
            tmp.z=s.z+dz[i];
            if(tmp.x<0||tmp.x>=sz[0]-1||tmp.y<0||tmp.y>=sz[1]-1||tmp.z<0||tmp.z>=sz[2]-1)
                continue;
            if(G[tmp.z][tmp.y][tmp.x]==1)
            {  
                S+=fun_S(s.z,s.y,s.x,i);
                continue;
            }
            if(!vis[tmp.z][tmp.y][tmp.x])
            {
                vis[tmp.z][tmp.y][tmp.x]=true;
                que.push(tmp);
            }
        }
    }
}

void init()
{
    V=S=0;
    memset(G,0,sizeof(G));
    memset(id,0,sizeof(id));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<3;i++)
    {
        sz[i]=0;
        loc[i].clear();
        loct[i].clear();
        loc[i].push_back(-1000);
        loc[i].push_back(2000);
    }
}
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            box[i].read();
        for(int i=0;i<3;i++)
        {
            for(set<int>::iterator it=loct[i].begin();it!=loct[i].end();it++)
                loc[i].push_back(*it);
            sz[i]=loc[i].size();
        }
        for(int i=0;i<3;i++)
            sort(loc[i].begin(),loc[i].end());
        for(int i=0;i<3;i++)
            for(int j=1;j<sz[i]-1;j++)
                id[i][loc[i][j]]=j;
        for(int t=0;t<n;t++)
            for(int i=id[2][box[t].zl];i<id[2][box[t].zr];i++)
                for(int j=id[1][box[t].yl];j<id[1][box[t].yr];j++)
                    for(int k=id[0][box[t].xl];k<id[0][box[t].xr];k++)
                        G[i][j][k]=1;
        bfs();
        V=3000ll*3000ll*3000ll-V;
        printf("%lld %lld\n",S,V);
    }
    return 0;
}
