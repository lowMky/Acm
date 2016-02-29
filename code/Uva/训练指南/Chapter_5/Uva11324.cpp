/*
ID: onlyazh1
LANG: C++
TASK: Knights of the Round Table
*/

#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;

const int MAXN=1010;
const int MAXM=50010;
int n,m,u,v,tot,idx,top,block;
int low[MAXN];
int dfn[MAXN];
int cnt[MAXN];
int head[MAXN];
int Stack[MAXN];
int belong[MAXN];
bool instack[MAXN];
bool G[MAXN][MAXN];
struct Edge{
    int v,nex;
}edge[MAXM];

void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

int dfs(int u){
    int res=cnt[u];
    for(int v=1;v<=block;v++)
        if(G[u][v]) res=max(res,dfs(v)+cnt[u]);
    return res;
}

void Tarjan(int u){
    low[u]=dfn[u]=++idx;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].v;
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        block++;int vn;
        do{
            vn=Stack[--top];
            cnt[block]++;
            instack[vn]=false;
            belong[vn]=block;
        }while(vn!=u);
    }
}

void init(){
    tot=top=idx=block=0;
    memset(G,false,sizeof(G));
    memset(cnt,0,sizeof(cnt));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(head,-1,sizeof(head));
    memset(instack,false,sizeof(instack));
}
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        init();
        cin>>n>>m;
        while(m--){
            cin>>u>>v;
            addedge(u,v);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i);
        for(int u=1;u<=n;u++){
            for(int i=head[u];i!=-1;i=edge[i].nex){
                int v=edge[i].v;
                if(belong[u]!=belong[v])
                    G[belong[u]][belong[v]]=true;
            }
        }
        int ans=0;
        for(int i=1;i<=block;i++)
            ans=max(ans,dfs(i));
        cout<<ans<<endl;
    }
    return 0;
}
