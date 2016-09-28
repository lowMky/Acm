#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1010;
const int maxm=10010;
const ll inf=1e18;

struct Edge{
    int u,v,nex;ll w;
}edge[maxm<<1];

int tot;
int head[maxn];
int n,m,s,t;
ll L;
set<int> S;
void addedge(int u,int v,ll w){
    if(!w) S.insert(tot);
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nex=head[u];
    head[u]=tot++;
    if(!w) S.insert(tot);
    edge[tot].u=v;
    edge[tot].v=u;
    edge[tot].w=w;
    edge[tot].nex=head[v];
    head[v]=tot++;
}

struct Node{
    int u;ll w;
    Node(){}
    Node(int _u,ll _w):u(_u),w(_w){}

    bool operator < (const Node & A)const{
        return w>A.w;
    }
};

bool vis[maxn];
ll dist[maxn];
priority_queue<Node> que;

ll Dijkstra(){
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    while(!que.empty())
        que.pop();

    dist[s]=0;
    que.push(Node(s,0));

    int v;ll w;
    Node now,nex;
    while(!que.empty()){
        now=que.top();que.pop();
        if(vis[now.u]) continue;
        vis[now.u]=true;
//        cout<<now.u<<" "<<dist[now.u]<<endl;
        for(int i=head[now.u];i!=-1;i=edge[i].nex){
            v=edge[i].v;w=edge[i].w;
            if(dist[v]>dist[now.u]+w){
                dist[v]=dist[now.u]+w;
                que.push(Node(v,dist[v]));
            }
        }
    }
    return dist[t];
//    if(!flag) cout<<t<<" "<<dist[t]<<endl;
}

ll check(ll m){
    for(set<int>::iterator it=S.begin();it!=S.end();){
        edge[*it].w=edge[(*it)^1].w=1+min(m,ll(1e9+10));
        m-=(edge[*it].w-1);++it;++it;
    }
    return Dijkstra();
}

int main(){
    //freopen("in.txt","r",stdin);
//    ifstream cin("in.txt");
    int u,v;ll w;
    cin>>n>>m>>L>>s>>t;

    tot=0;
    S.clear();
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    ll l=0,r=inf,kk;
    if(check(0)>L||check(r)<L){
        printf("NO\n");return 0;
    }

    printf("YES\n");
    while(l<=r){
        ll mid=(l+r)>>1;
        kk=check(mid);
        if(kk>L) r=mid-1;
        else if(kk<L) l=mid+1;
        else break;
    }
    for(int i=0;i<tot;i+=2)
        printf("%d %d %lld\n",edge[i].u,edge[i].v,edge[i].w);
    return 0;
}
