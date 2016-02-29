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

const int MAXN=20010;
const int MAXM=50010;
int n,m,u,v,tot,idx,top,block;
int low[MAXN];
int dfn[MAXN];
int head[MAXN];
int Stack[MAXN];
int belong[MAXN];
int in[MAXN];
int out[MAXN];
bool instack[MAXN];

struct Edge{
    int v,nex;
}edge[MAXM];

void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
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
            instack[vn]=false;
            belong[vn]=block;
        }while(vn!=u);
    }
}

void init(){
    tot=top=idx=block=0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
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
        int ans=0;
        for(int u=1;u<=n;u++){
            for(int i=head[u];i!=-1;i=edge[i].nex){
                int v=edge[i].v;
                if(belong[u]!=belong[v]){
                    out[belong[u]]++;
                    in[belong[v]]++;
                }
            }
        }
        if(n==1||block==1){
            cout<<0<<endl;
            continue;
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=block;i++){
            if(!in[i]) ans1++;
            if(!out[i]) ans2++;
        }
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
