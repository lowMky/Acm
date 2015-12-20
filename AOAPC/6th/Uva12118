/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月16日 星期五 16时56分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int cnt[1100];
int deg[1100];
int par[1100];
bool vis[1100];
int n,m,t;
int u,v;
void init()
{
    for(int i=0;i<1100;i++)
        par[i]=i;
    memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
    memset(cnt,0,sizeof(cnt));
}

int find(int x)
{
    return x==par[x]?x:par[x]=find(par[x]);
}
int main()
{
    int icase=0;
    while(scanf("%d%d%d",&n,&m,&t)&&(n+m+t))
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
            u=find(u);
            v=find(v);
            if(u!=v)
                par[u]=v;
            vis[v]=true;
        }
        printf("Case %d: ",++icase);
        if(!m)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<1100;i++)
            if(deg[i]%2)    
                cnt[find(i)]++;
        int ans=0;
        for(int i=0;i<1100;i++)
            if(vis[i]&&par[i]==i)
                ans+=max(cnt[i],2);
        ans=t*(max((ans-2)/2,0)+m);
        printf("%d\n",ans);
    }
    return 0;
}
