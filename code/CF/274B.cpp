#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

ll val[maxn];
ll dp[maxn][2];
vector<int> G[maxn];

void dfs(int x,int fa){
    ll s=0,z=0;
    for(int i=0,sz=G[x].size();i<sz;++i){
        if(G[x][i]==fa) continue;
        dfs(G[x][i],x);
        z=max(z,dp[G[x][i]][0]);
        s=max(s,dp[G[x][i]][1]);
    }
    dp[x][0]=z;dp[x][1]=s;
    val[x]=val[x]+z-s;
    if(val[x]<0)
        dp[x][0]-=val[x];
    else dp[x][1]+=val[x];
}

int main(){
    int n;cin>>n;
    int u,v;
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        cin>>val[i];

    dfs(1,-1);
    cout<<dp[1][0]+dp[1][1]<<endl;
    return 0;
}
