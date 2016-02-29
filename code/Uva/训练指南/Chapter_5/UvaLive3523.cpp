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
const int MAXM=1000010;
int n,m,u,v,tot;
int low[MAXN];
int dfn[MAXN];
int head[MAXN];
int Stack[MAXN];
int tmp[MAXN];
int color[MAXN];
bool ok[MAXN];
bool can[MAXN];
bool instack[MAXN];
bool G[MAXN][MAXN];
int idx,top,cc;
struct Edge{
    int v,nex;
}edge[MAXM<<1];

void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

bool dfs(int u,int col){
    color[u]=col;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].v;
        if(!ok[v]) continue;
        if(color[v]!=-1){
            if(color[v]==col) return false;
            continue;
        }
        if(!dfs(v,!col)) return false;
    }
    return true;
}

void Tarjan(int u,int pre){
    low[u]=dfn[u]=++idx;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].v;
        if(v==pre) continue;
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                int vn,cc=0;
                memset(ok,false,sizeof(ok));
                do{
                    vn=Stack[--top];
                    ok[vn]=true;
                    tmp[cc++]=vn;
                    instack[vn]=false;
                }while(vn!=v);
                ok[u]=true;
                memset(color,-1,sizeof(color));
                if(!dfs(u,0)){
                    can[u]=true;
                    while(cc--) can[tmp[cc]]=true;
                }
            }
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
}

void init(){
    tot=top=idx=0;
    memset(G,false,sizeof(G));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(can,false,sizeof(can));
    memset(head,-1,sizeof(head));
    memset(instack,false,sizeof(instack));
}
int main(){
    //ifstream cin("in.txt");
    while(cin>>n>>m&&n+m){
        init();
        while(m--){
            cin>>u>>v;
            G[u][v]=G[v][u]=true;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&!G[i][j])
                    addedge(i,j);

        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i,i);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!can[i]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
