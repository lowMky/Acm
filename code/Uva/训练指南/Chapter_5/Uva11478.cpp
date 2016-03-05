/*
ID: onlyazh1
LANG: C++
TASK: Halum
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

const int maxn=600;
const int maxm=4000;
const int INF=0x3f3f3f3f;
int n,m,u,v,w,tot;
int head[maxn];
int cnt[maxn];
int dist[maxn];
bool inque[maxn];
struct Edge{
    int v,nex,w;;
}edge[maxm];

void addedge(int u,int v,double w){
    edge[tot].v=v;edge[tot].w=w;
    edge[tot].nex=head[u];head[u]=tot++;
}

bool bellman(){
    memset(cnt,0,sizeof(cnt));
    memset(inque,true,sizeof(inque));
    queue<int> Que;
    for(int i=1;i<=n;i++){
        dist[i]=0;inque[i]=true;Que.push(i);
    }
    while(!Que.empty()){
        int u=Que.front();Que.pop();
        inque[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].nex){
            int v=edge[i].v;
            if(dist[v]>dist[u]+edge[i].w){
                dist[v]=dist[u]+edge[i].w;
                if(!inque[v]){
                    Que.push(v);inque[v]=true;
                    if(++cnt[v]>n) return true;
                }
            }
        }
    }
    return false;
}
int test(int x){
    bool res=false;
    for(int i=0;i<tot;i++)
        edge[i].w-=x;
    res=bellman();
    for(int i=0;i<tot;i++)
        edge[i].w+=x;
    return res;
}
int main(){
    //ifstream cin("in.txt");
    while(cin>>n>>m){
        tot=0;int ub=0;
        memset(head,-1,sizeof(head));
        while(m--){
            cin>>u>>v>>w;
            addedge(u,v,w);
            ub=max(ub,w);
        }
        if(!test(ub)) cout<<"Infinite"<<endl;
        else if(test(1)) cout<<"No Solution"<<endl;
        else{
            int L=1,R=ub;
            while(L<R){
                int M=L+(R-L+1)/2;
                if(test(M)) R=M-1;
                else L=M;
            }
            cout<<L<<endl;
        }
    }
    return 0;
}


