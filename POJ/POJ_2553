/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月22日 星期二 19时55分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=6000;
int out[maxn];
int low[maxn];
int dfn[maxn];
int stack[maxn];
bool instack[maxn];
int inde,top,block,tot;
int belong[maxn];
vector<int> bblock[maxn];
vector<int> G[maxn];
int ans[maxn];
int u,v,n,m;
void  tarjan(int u)
{
    dfn[u]=low[u]=++inde;
    stack[++top]=u;
    instack[u]=true;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!dfn[v])
        {
             tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        block++;
        do{
            v=stack[top--];
            instack[v]=false;
            bblock[block].push_back(v);
            belong[v]=block;
        }while(u!=v);
    }   
}

void init()
{
    for(int i=0;i<maxn;i++)
    {
        G[i].clear();
        bblock[i].clear();
    }
    tot=block=inde=top=0;
    memset(out,0,sizeof(out));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(belong,0,sizeof(belong));
}
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        init();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                int v=G[i][j];
                if(belong[i]!=belong[v])
                    out[belong[i]]++;
            }
        }
        for(int i=1;i<=block;i++)
            if(out[i]==0)
            {
                for(int j=0;j<bblock[i].size();j++)
                    ans[tot++]=bblock[i][j];
            }

        sort(ans,ans+tot);
        //for(int i=1;i<=block;i++)
        //    printf("%d\n",bblock[i].size());
        //printf("%d %d\n",tot,block); 
        for(int i=0;i<tot;i++)
            {
                 printf("%d",ans[i]);
                 if(i<tot-1)
                    printf(" ");
            }  
        puts("");
    }    
    return 0;
}
