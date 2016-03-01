/*
ID: onlyazh1
LANG: C++
TASK: Walk Through the Forest
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

const int maxn=1010;
const int maxm=1000010;
const int INF=0x3f3f3f3f;
int n,m,s,e,u,v,w;
int G[maxn][maxn];
bool G2[maxn][maxn];
int dist[maxn];
struct Node{
    int u;int w;
    Node(){};
    Node(int _u,int _w){
        u=_u;w=_w;
    }
    bool operator < (const Node &A) const{
        return w>A.w;
    }
};

void Dijkstra(int s){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    priority_queue<Node> Que;
    dist[s]=0;
    Que.push(Node(s,0));
    while(!Que.empty()){
        Node u=Que.top();Que.pop();
        for(int i=0;i<n;i++){
            if(G[u.u][i]==INF) continue;
            if(dist[i]>G[u.u][i]+u.w){
                dist[i]=G[u.u][i]+u.w;
                Que.push(Node(i,dist[i]));
            }
        }
    }
}
int dp[maxn];
int dfs(int u){
    if(dp[u]!=-1) return dp[u];
    if(u==1) return dp[u]=1;
    int sum=0;
    for(int v=0;v<n;v++)
        if(G2[u][v]) sum+=dfs(v);
    return dp[u]=sum;
}
int main(){
    //ifstream cin("in.txt");
    while(cin>>n&&n){
        cin>>m;
        memset(G,0x3f3f3f3f,sizeof(G));
        memset(G2,false,sizeof(G2));
        memset(dp,-1,sizeof(dp));
        while(m--){
            cin>>u>>v>>w;
            G[--u][--v]=w;
            G[v][u]=w;
        }
        Dijkstra(1);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(G[i][j]==INF) continue;
                if(dist[i]<dist[j]) G2[j][i]=true;
                else if(dist[i]>dist[j]) G2[i][j]=true;
            }
        cout<<dfs(0)<<endl;
    }
    return 0;
}
