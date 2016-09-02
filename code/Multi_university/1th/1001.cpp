#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int maxm=1000100;
const int maxn=100010;

struct Edge{
    int u,v;
    ll w;
}edge[maxm];

struct Eddge{
    int v;
    ll w;
    Eddge(){}
    Eddge(int _v,ll _w){
        v=_v;w=_w;
    }
};

vector<pair<int,ll> >G[maxn];

ll n,m;
int par[maxn];
ll son[maxn];
ll ans;

bool cmp(Edge A,Edge B){
    return A.w<B.w;
}


int find(int x){
    return par[x]=(x==par[x]?x:find(par[x]));
}

void init(){
    for(int i=0;i<=n;++i)
        par[i]=i;
}

void dfs(int rt,int par){
    son[rt]=1;
    for(int i=0,sz=G[rt].size();i<sz;++i){
        if(G[rt][i].first==par)
            continue;
        dfs(G[rt][i].first,rt);
        son[rt]+=son[G[rt][i].first];
    }
}

void dfss(int rt,int par){
    for(int i=0,sz=G[rt].size();i<sz;++i){
        if(G[rt][i].first==par)
            continue;
        ans+=2*G[rt][i].second*son[G[rt][i].first]*(n-son[G[rt][i].first]);
        dfss(G[rt][i].first,rt);
    }
}
void Prim(){
    ll ans1=0;
    init();
    sort(edge,edge+m,cmp);
    int cnt=0,u,v;
    for(int i=0;i<m;++i){
        u=find(edge[i].u);
        v=find(edge[i].v);
        if(u==v) continue;
        par[v]=u;
        ans1+=edge[i].w;
        cnt++;
        G[edge[i].u].push_back(make_pair(edge[i].v,edge[i].w));
        G[edge[i].v].push_back(make_pair(edge[i].u,edge[i].w));
        if(cnt==n-1) break;
    }
    dfs(1,-1);
    ans=0;
    dfss(1,-1);
    printf("%lld %.2f\n",ans1,ans*1.0/(n*n-n));
}



int main(){
//    freopen("in.txt","r",stdin);

    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;++i)
            G[i].clear();
        for(int i=0;i<m;++i)
            scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
        Prim();
    }
    return 0;
}
