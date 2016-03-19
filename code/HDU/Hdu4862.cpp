/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
*/

#include<iostream>
#include<map>
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
const int maxn=1000;
const int maxm=200010;
const int INF=0x3f3f3f3f;
struct Edge{
    int to,next,cap,flow,cost;
}edge[maxm<<1];
char G[20][20];
int head[maxn],tot;
int pre[maxn],dis[maxn];
bool vis[maxn];
void addedge(int u,int v,int cap,int cost){
    edge[tot].to=v;edge[tot].cap=cap;edge[tot].cost=cost;
    edge[tot].flow=0;edge[tot].next=head[u];head[u]=tot++;
    edge[tot].to=u;edge[tot].cap=0;edge[tot].cost=-cost;
    edge[tot].flow=0;edge[tot].next=head[v];head[v]=tot++;
}
queue<int>q;
bool spfa(int s,int t,int n)
{
    while(!q.empty()) q.pop();
    for(int i=0;i<n;i++)
    {
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)return false;
    else return true;
}

int minCostMaxflow(int s,int t,int n,int &cost)
{
    int flow=0;cost=0;int cnt=0;
    while(spfa(s,t,n))
    {
        int Min=INF;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to])
        {
            if(Min>edge[i].cap-edge[i].flow)
                Min=edge[i].cap-edge[i].flow;
        }
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to])
        {
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}

int main(){
    //ifstream cin("in.txt");
    int n,m,c,icase=0;
    int T;cin>>T;
    while(T--){
        cin>>n>>m>>c;
        for(int i=0;i<n;i++)
            cin>>G[i];
        cout<<"Case "<<++icase<<" : ";
        if(c<min(n,m)){
            cout<<-1<<endl;
            continue;
        }
        tot=0;
        memset(head,-1,sizeof(head));
        addedge(2*n*m,2*n*m+2,c,0);
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++){
                    addedge(2*n*m,2*(i*m+j),1,0);
                    addedge(2*(i*m+j)+1,2*n*m+2,1,0);
                    addedge(2*(i*m+j),2*(i*m+j)+1,1,-10000);
                    for(int t=i+1;t<n;t++)
                        addedge(2*(i*m+j)+1,2*(t*m+j),1,(t-i-1)-(G[i][j]==G[t][j]?G[i][j]-'0':0));
                    for(int t=j+1;t<m;t++)
                        addedge(2*(i*m+j)+1,2*(i*m+t),1,(t-j-1)-(G[i][j]==G[i][t]?G[i][j]-'0':0));
                }
            addedge(2*n*m+1,2*n*m,c,0);
            int ans;minCostMaxflow(2*n*m+1,2*n*m+2,2*n*m+3,ans);
        cout<<(ans+10000*n*m)*-1<<endl;
    }
    return 0;
}
