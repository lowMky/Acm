/*
ID: onlyazh1
LANG: C++
TASK: test
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1010;

struct Edge{
    int u,v;ll w;
    bool operator < (const Edge &A) const{
        return w>A.w;
    }
}edge[1001000*2];
ll M[maxn][maxn];
bool vis[maxn][maxn];
int par[1001000];
int cnt[1001000];
int n,m;ll k,tag;

int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
struct node{
    int idx;ll val;
    bool operator < (const node &A)const {
        return val>A.val;
    }
}node[1001000];

int te,tn;
void addedge(int u,int v,ll w){
    edge[te].u=u;
    edge[te].v=v;
    edge[te++].w=w;
}

bool ok(int tx,int ty,ll val){
    if(tx<0||tx>=n) return false;
    if(ty<0||ty>=m) return false;
    if(M[tx][ty]<val||vis[tx][ty]) return false;
    return true;
}
queue<int> Que;

void bfs(int idx,ll val){
    int z=k/val;int c=1;
    int x,y,tx,ty,loc;
    while(!Que.empty()) Que.pop();
    Que.push(idx);
    vis[idx/m][idx%m]=true;
    if(c==z) return ;
    while(!Que.empty()){
        loc=Que.front();Que.pop();
        x=loc/m;y=loc%m;
        for(int i=0;i<4;i++){
            tx=x+dx[i];
            ty=y+dy[i];
            if(ok(tx,ty,val)){
                Que.push(tx*m+ty);
                vis[tx][ty]=true;
                c++;
                if(c==z) return;
            }
        }
    }
}

int find(int x){
    return par[x]=(x==par[x]?x:find(par[x]));
}

void init(int n){
    tn=te=0;
    for(int i=0;i<=n;i++){
        par[i]=i;cnt[i]=1;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    cin>>n>>m>>k;
    init(n*m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>M[i][j];
            if(M[i][j]&&k%M[i][j]==0){
                node[tn].idx=(i*m+j);
                node[tn++].val=M[i][j];
            }
            if(i) addedge((i-1)*m+j,i*m+j,min(M[i][j],M[i-1][j]));
            if(j) addedge(i*m+j-1,i*m+j,min(M[i][j],M[i][j-1]));
        }
    //cout<<n<<m<<te<<endl;
    sort(node,node+tn);
    sort(edge,edge+te);
    ll tag=0;
    int idx=0;bool flag=false;
    for(int i=0;i<tn&&!flag;i++){
        for(;idx<te;idx++){
            if(edge[idx].w>=node[i].val){
                int u=edge[idx].u;
                int v=edge[idx].v;
                u=find(u);v=find(v);
                if(u!=v){
                    par[v]=u;
                    cnt[u]+=cnt[v];
                }
            }
            else break;
        }
        if(cnt[find(node[i].idx)]>=k/node[i].val){
            tag=node[i].val;flag=true;bfs(node[i].idx,node[i].val);break;
        }
    }
    if(!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(vis[i][j]) cout<<tag;
                else cout<<0;
                cout<< (j<m-1?" ":"\n");
            }
    }
    return 0;
}
