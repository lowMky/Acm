#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const int inf=0x3f3f3f3f;
const ll MOD=1e9+7;





struct Node{
    int u,st;
    Node(){}
    Node(int _u,int _st){
        u=_u;st=_st;
    }
    bool operator < (const Node &A) const{
        return st>A.st;
    }
};

int M[310][310];
vector<int> G[maxn];
int n,m,p;
bool vis[maxn];
int dist[maxn];

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
priority_queue<Node> Que;

void bfs(int col){
    int nx,ny,tx,ty,cnt=0;
    while(!Que.empty()) Que.pop();
    memset(vis,false,sizeof(vis));
//    for(int i=0;i<n*m;++i)
//        if(M[i/m][i%m]>col)
//            dist[i]=inf;
    for(int i=0,sz=G[col].size();i<sz;++i)
        Que.push(Node(G[col][i],dist[G[col][i]]));

    Node now,to;
    int csize=G[col+1].size();
    while(!Que.empty()){
        now=Que.top();Que.pop();
//        cout<<"now.u="<<now.u<<endl;
        nx=now.u/m;ny=now.u%m;
        vis[now.u]=true;
        if(M[nx][ny]==col+1){
            dist[now.u]=now.st;
            cnt++;if(cnt==csize) return ;
        }

        for(int i=0;i<4;++i){
            tx=nx+dx[i];
            ty=ny+dy[i];
            if(tx<0||tx>=n||ty<0||ty>=m||vis[tx*m+ty])
                continue;
            Que.push(Node(tx*m+ty,now.st+1));
            vis[tx*m+ty]=true;
        }
    }
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);
    int s=0,e;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&M[i][j]);
            G[M[i][j]].push_back(i*m+j);
            if(M[i][j]==p)
                e=i*m+j;
        }
    }
    memset(dist,0x3f3f3f3f,sizeof(dist));
    int nx,ny,tx,ty;
    for(int i=0,sz=G[1].size();i<sz;++i){
        tx=G[1][i]/m;ty=G[1][i]%m;
        dist[G[1][i]]=tx+ty;
//        cout<<G[1][i]<<" "<<dist[G[1][i]]<<endl;
    }

    for(int i=1;i<p;++i){
        if(G[i].size()*G[i+1].size()>10*n*m)
            bfs(i);
        else for(int a=0,psz=G[i].size();a<psz;++a){
                nx=G[i][a]/m;ny=G[i][a]%m;
                for(int b=0,qsz=G[i+1].size();b<qsz;++b){
                    tx=G[i+1][b]/m;ty=G[i+1][b]%m;
                    dist[G[i+1][b]]=min(dist[G[i+1][b]],dist[G[i][a]]+abs(tx-nx)+abs(ty-ny));
                }
            }
    }
    printf("%d\n",dist[e]);
    return 0;
}

