/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
typedef long long ll;
const int maxn=20010;
const int maxm=200010;
const double INF=1e20;
const double eps=1e-8;
struct Edge{
    int to,next;
    double cap,flow;
}edge[maxm],tmpG[maxm];

int n,tot,toth,totv;
int head[maxn],tmph[maxn];
int gap[maxn],dep[maxn],cur[maxn];

void addedge(int u,int v,double w,double rw=0){
    edge[tot].to=v;edge[tot].cap=w;edge[tot].flow=0;
    edge[tot].next=head[u];head[u]=tot++;
    edge[tot].to=u;edge[tot].cap=rw;edge[tot].flow=0;
    edge[tot].next=head[v];head[v]=tot++;
}


int Q[maxn];
void BFS(int s,int e,Edge *edge)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int front=0,rear=0;
    dep[e]=0;
    Q[rear++]=e;
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
int sap(int s,int e,int n,Edge *edge)
{
    memcpy(cur,head,sizeof(head));
    BFS(s,e,edge);

    int top=0;int u=s;
    double ans=0;
    while(dep[s]<n)
    {
        if(u==e)
        {
            double Min=INF;
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
        int Min=n;
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
        if(u!=s)
            u=edge[S[--top]^1].to;
    }
    return ans;
}


void rebuild(double s){
    for(int i=0;i<tot;i++){
        tmpG[i]=edge[i];
        if(i>=toth&&i%2==0)
            tmpG[i].cap=s;
    }
}

void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
int num[maxn];
int main(){
    //ifstream cin("in.txt");
    int T,icase=0;cin>>T;
    while(T--){
        init();
        cin>>n;totv=n+2;
        for(int i=0;i<n;i++)
            cin>>num[i];

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(num[i]>num[j]){
                    addedge(totv,i,INF);
                    addedge(totv++,j,INF);
                }
            }
        for(int i=n+2;i<totv;i++)
            addedge(n,i,1);
        toth=tot;
        for(int i=0;i<n;i++)
            addedge(i,n+1,0);
        double l=0,r=tot*1.0;
        while(r-l>=eps){
            double mid=(l+r)/2;
            rebuild(mid);
            if(totv-n-2-sap(n,n+1,totv,tmpG)<eps)
                r=mid;
            else l=mid;
        }
        printf("Case #%d: %.8f\n",++icase,l);
    }
    return 0;
}
