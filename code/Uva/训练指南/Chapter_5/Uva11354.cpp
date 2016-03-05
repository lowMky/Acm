/*
ID: onlyazh1
LANG: C++
TASK: Low Cost Air Travel
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

const int maxn=100010;
const int maxm=200010;
const int INF=0x3f3f3f3f;
int n,m,u,v,w,tot;
int head[maxn];
int fa[maxn];
int L[maxn];
int cost[maxn];
int dist[maxn];
int anc[maxn][20];
int maxcost[maxn][20];
struct Edge{
    int u,v,w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}edge[maxm];

struct Node{
    int v,w;
    Node(){}
    Node(int _v,int _w){v=_v;w=_w;}
};
vector<Node> G[maxn];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}

void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v;int w=G[u][i].w;
        if(fa[v]==-1){
            L[v]=L[u]+1;
            fa[v]=u;
            cost[v]=w;
            dfs(v);
        }
    }
}

void Kruskal(){
    for(int i=0;i<n;i++){
        fa[i]=i;G[i].clear();
    }
    sort(edge,edge+m);
    int cnt=0;
    for(int i=0;i<m;i++){
        u=edge[i].u;
        v=edge[i].v;
        w=edge[i].w;
        int x=find(u);int y=find(v);
        if(x!=y){
            fa[y]=x;cnt++;
            G[u].push_back(Node(v,edge[i].w));
            G[v].push_back(Node(u,edge[i].w));
            if(cnt==n-1) return;
        }
    }
}
void preprocess(){
    memset(anc,-1,sizeof(anc));
    for(int i=0;i<n;i++){
        anc[i][0]=fa[i];maxcost[i][0]=cost[i];
    }
    for(int j=1;(1<<j)<n;j++)
        for(int i=0;i<n;i++)
            if(anc[i][j-1]!=-1){
                int a=anc[i][j-1];
                anc[i][j]=anc[a][j-1];
                maxcost[i][j]=max(maxcost[i][j-1],maxcost[a][j-1]);
            }
}

int query(int u,int v){
    int tmp,log;
    if(L[u]<L[v]) swap(u,v);
    for(log=1;(1<<log)<=L[u];log++);log--;
    int ans=-INF;
    for(int i=log;i>=0;i--)
        if(L[u]-(1<<i)>=L[v]){ans=max(ans,maxcost[u][i]);u=anc[u][i];}
    if(u==v) return ans;
    for(int i=log;i>=0;i--)
        if(anc[u][i]!=-1&&anc[u][i]!=anc[v][i]){
            ans=max(ans,maxcost[u][i]);u=anc[u][i];
            ans=max(ans,maxcost[v][i]);v=anc[v][i];
        }
    ans=max(ans,cost[u]);
    ans=max(ans,cost[v]);
    return ans;
}
int main(){
    ifstream cin("in.txt");
    int icase=0;
    while(cin>>n>>m){
        if(icase++) cout<<endl;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;u--,v--;
            edge[i].u=u;edge[i].v=v;edge[i].w=w;
        }
        Kruskal();
        memset(fa,-1,sizeof(fa));
        fa[0]=L[0]=cost[0]=0;dfs(0);
        preprocess();
        cin>>m;
        while(m--){
            cin>>u>>v;u--,v--;
            cout<<query(u,v)<<endl;
        }
    }
    return 0;
}


