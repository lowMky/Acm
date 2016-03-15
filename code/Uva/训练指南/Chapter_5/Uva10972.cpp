/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
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
typedef long long ll;

vector<int> G[1100];
int in[1100];
int deg[1100];
int low[1100];
int dfn[1100];
int Stack[1100];
int belong[1100];
bool instack[1100];
int top,block,idx;
void Tarjan(int u,int pre){
    int v;
    low[u]=dfn[u]=++idx;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=0,sz=G[u].size();i<sz;i++){
        v=G[u][i];
        if(v==pre) continue;
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        block++;
        do{
            v=Stack[--top];
            instack[v]=false;
            belong[v]=block;
        }while(v!=u);
    }
}

void init(){
    block=idx=top=0;
    for(int i=0;i<1010;i++)
        G[i].clear();
    memset(deg,0,sizeof(deg));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
int main(){
    //ifstream cin("in.txt");
    int n,m,u,v;
    while(cin>>n>>m){
        init();
        while(m--){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for(int i=1;i<=n;i++)
            if(!dfn[i]) Tarjan(i,-1);

        for(int u=1;u<=n;u++)
            for(int j=0,sz=G[u].size();j<sz;j++){
                v=G[u][j];
                if(belong[u]!=belong[v]){
                    deg[belong[v]]++,deg[belong[u]]++;
                }
            }
        if(block==1){
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=block;i++)
            if(deg[i]==2) ans++;
            else if(deg[i]==0) ans+=2;
        cout<<(ans+1)/2<<endl;
    }
    return 0;
}
