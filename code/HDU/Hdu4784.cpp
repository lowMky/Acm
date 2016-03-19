/*
ID: onlyazh1
LANG: C++
TASK:
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

const int maxn=550;
const int maxm=5500;
const int INF=0x3f3f3f3f;
struct Edge{
    int v,tc,mc,nex;
}G[maxm],G2[maxm];

struct Node{
    int u,t,sal,moy;
    Node(){};
    Node(int _u,int _t,int _sal){
        u=_u;t=_t;sal=_sal;
    }
    bool operator < (const Node &A)const {
        return t<A.t;
    }
};
int sale[550];
int dist[550];
int head[550];
int head2[550];
int vis[550][350][6];
bool tag[550][350][6];
bool visit[550];
int N,M,B,K,R,T;
int u,v;int tc,mc;
int tot,tot2,top,top2;
int Sta[550];
priority_queue<Node> Que;
void addedge(int u,int v,int tc,int mc,Edge *edge,int *head,int &tot){
    edge[tot].v=v;edge[tot].tc=tc;edge[tot].mc=mc;
    edge[tot].nex=head[u];head[u]=tot++;
}

void SPFA(int s,Edge *edge,int *head){
    memset(visit,false,sizeof(visit));
    memset(dist,0x3f3f3f3f,sizeof(dist));
    visit[s]=true;dist[s]=0;
    Sta[++top2]=s;
    while(top2){
        int u=Sta[top2--];
        visit[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].nex){
            int v=edge[i].v;
            if(dist[v]>dist[u]+edge[i].tc){
                dist[v]=dist[u]+edge[i].tc;
                if(!visit[v]){
                    visit[v]=true;
                    Sta[++top2]=v;
                }
            }
        }
    }
}
void SPFA2(int s,int t,int salt,int moy){
    vis[s][t][salt]=moy;
    tag[s][t][salt]=true;
    while(!Que.empty()) Que.pop();
    Que.push(Node(s,t,salt));
    while(!Que.empty()){
        Node tmp=Que.top();Que.pop();
        tag[tmp.u][tmp.t][tmp.sal]=false;
        if(tmp.u==N) continue;
        for(int i=head[tmp.u];i!=-1;i=G[i].nex){
            int v=G[i].v;
            if(tmp.t<dist[tmp.u]||(v!=N&&v%N==0)||(v!=1&&v%N==1))
                continue;
            int lefm=vis[tmp.u][tmp.t][tmp.sal]-G[i].mc;
            int left=tmp.t-G[i].tc;
            if(left<0) continue;
            if(tmp.u==1||tmp.u==N){
                if(lefm>vis[v][left][tmp.sal]){
                    vis[v][left][tmp.sal]=lefm;
                    if(!tag[v][left][tmp.sal]){
                        tag[v][left][tmp.sal]=true;
                        Que.push(Node(v,left,tmp.sal));
                    }
                }
                continue;
            }

            for(int j=max(tmp.sal-1,0);j<=min(tmp.sal+1,B);j++){
                if(lefm-(j-tmp.sal)*sale[tmp.u]>vis[v][left][j]){
                    vis[v][left][j]=lefm-(j-tmp.sal)*sale[tmp.u];
                    if(!tag[v][left][j]){
                        tag[v][left][j]=true;
                        Que.push(Node(v,left,j));
                    }
                }
            }
        }
    }
}

void init(){
    tot=tot2=top2=0;
    memset(head,-1,sizeof(head));
    memset(head2,-1,sizeof(head2));
}
int main(){
    //freopen("in.txt","r",stdin);
    int Tcase,icase=0;
    scanf("%d",&Tcase);
    while(Tcase--){
        init();
        scanf("%d%d%d%d%d%d",&N,&M,&B,&K,&R,&T);
        for(int i=0;i<K;i++)
            for(int j=1;j<=N;j++)
                scanf("%d",&sale[i*N+j]);

        for(int i=0;i<M;i++){
            scanf("%d%d%d%d",&u,&v,&tc,&mc);
            for(int j=0;j<K;j++){
                addedge(j*N+u,j*N+v,tc,mc,G,head,tot);
                addedge(j*N+v,j*N+u,tc,mc,G2,head2,tot2);
            }
        }

        for(int i=0;i<K;i++)
            for(int j=2;j<N;j++){
                addedge(j+i*N,j+((i+1)%K)*N,1,0,G,head,tot);
                addedge(j+((i+1)%K)*N,j+i*N,1,0,G2,head2,tot2);
            }
        SPFA(N,G2,head2);
        printf("Case #%d: ",++icase);
        if(dist[1]>T){
            printf("Forever Alone\n");
            continue;
        }
        for(int i=0;i<=K*N;i++)
            for(int j=0;j<=T;j++)
                for(int k=0;k<=B;k++)
                    vis[i][j][k]=-1,tag[i][j][k]=false;
        SPFA2(1,T,0,R);
        int res=-1;
        for(int i=0;i<=T;i++)
            for(int j=0;j<=B;j++)
                res=max(res,vis[N][i][j]);
        if(res==-1) printf("Forever Alone\n");
        else printf("%d\n",res);
    }
    return 0;
}
