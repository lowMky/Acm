/*
ID: onlyazh1
LANG: C++
TASK: Going in Cycle!!
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

const int maxn=60;
const int maxm=4000;
const int INF=0x3f3f3f3f;
int n,m,u,v,tot;
double w;
int head[maxn];
int cnt[maxn];
double dist[maxn];
bool inque[maxn];
struct Edge{
    int v,nex;double w;
}edge[maxm];

void addedge(int u,int v,double w){
    edge[tot].v=v;edge[tot].w=w;
    edge[tot].nex=head[u];head[u]=tot++;
}

bool bellman(){
    memset(cnt,0,sizeof(cnt));
    queue<int> Que;
    for(int i=1;i<=n;i++){
        Que.push(i);
        dist[i]=0;inque[i]=true;
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
bool test(double x){
    bool res=false;
    for(int i=0;i<tot;i++)
        edge[i].w-=x;
    res=bellman();
    for(int i=0;i<tot;i++)
        edge[i].w+=x;
    return res;
}
int main(){
    ifstream cin("in.txt");
    int icase=0,T;cin>>T;
    while(T--){
        memset(head,-1,sizeof(head));
        tot=0;
        double ub=0;
        cin>>n>>m;
        while(m--){
            cin>>u>>v>>w;
            addedge(u,v,w);
            ub=max(ub,w);
        }
        cout<<"Case #"<<++icase<<": ";
        if(!test(ub+1)) cout<<"No cycle found."<<endl;
        else{
            double L=0,R=ub;
            while(R-L>1e-3){
                double M=L+(R-L)/2;
                if(test(M)) R=M;
                else L=M;
            }
            cout<<fixed<<setprecision(2)<<R<<endl;
        }
    }
    return 0;
}


