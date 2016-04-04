/*
ID: onlyazh1
LANG: C++
TASK: Delivery Bears
*/

#include<iostream>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<sstream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=100;
const int maxm=100100;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct Edge{
    int to,next,cap,flow;
}edge[maxm];
int tol;int head2[maxn];
int gap[maxn],dep[maxn],cur[maxn];

int tmph[maxn];
Edge tmpG[maxm];

void init(){
    tol=0;
    memset(head2,-1,sizeof(head2));
}


void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].flow=0;
    edge[tol].next=head2[u];head2[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].flow=0;
    edge[tol].next=head2[v];head2[v]=tol++;
}
int Q[maxn];
void BFS(int start,int end,Edge *edge,int *head)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int front=0,rear=0;
    dep[end]=0;
    Q[rear++]=end;
    while(front!=rear)
    {
        int u=Q[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1)
                continue;
            Q[rear++]=v;
            dep[v]=dep[u]+1;
            gap[dep[v]]++;
        }
    }
}
int S[maxn];
int sap(int start,int end,int N,Edge *edge,int *head)
{
    memcpy(cur,head2,sizeof(head2));
    BFS(start,end,edge,head);

    int top=0;
    int u=start;
    int ans=0;
    while(dep[start]<N)
    {
        if(u==end)
        {
            int Min=INF;
            int inser;
            for(int i=0;i<top;i++)
                if(Min>edge[S[i]].cap-edge[S[i]].flow)
                {
                    Min=edge[S[i]].cap-edge[S[i]].flow;
                    inser=i;
                }
            for(int i=0;i<top;i++)
            {
                edge[S[i]].flow+=Min;
                edge[S[i]^1].flow-=Min;
            }
            ans+=Min;
            top=inser;
            u=edge[S[top]^1].to;
            continue;
        }
        bool flag=false;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u])
            {
                flag=true;
                cur[u]=i;
                break;
            }
        }
        if(flag)
        {
            S[top++]=cur[u];
            u=v;
            continue;
        }
        int Min=N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min)
            {
                Min=dep[edge[i].to];
                cur[u]=i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u]=Min+1;
        gap[dep[u]]++;
        if(u!=start)
            u=edge[S[--top]^1].to;
    }
    return ans;
}
int main(){
    //ifstream cin("in.txt");
    init();
    int n,m,k,u,v,w;
    double ans=INF*1.0;
    cin>>n>>m>>k;
    while(m--){
        cin>>u>>v>>w;
        addedge(u,v,w);
        ans=min(ans,(double)w);
    }
    double l=0.0,r=10000000.0;
    for(int i=0;i<2000;i++){
        double mid=l+(r-l)/2;
        //cout << l << ' ' << r << ' ' << mid << endl;
        for(int i=0;i<tol;i++){
            tmpG[i]=edge[i];
            if(i%2==0) tmpG[i].cap=floor(edge[i].cap*1.0/mid);
            //if(i%2==0) cout<<tmpG[i].cap<<endl;
        }
        for(int i=1;i<=n;i++) tmph[i]=head2[i];
        if(sap(1,n,n,tmpG,tmph)>=k) l=mid;
        else r=mid;
    }
    printf("%.7f\n",max(k*1.0*l,ans));
    return 0;
}
