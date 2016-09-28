#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e18;
const int MOD=1e9;

vector<int> G[maxn];
int par[maxn];
int dep[maxn];
int son[maxn];
double ans[maxn];

void dfs(int rt){
    son[rt]=1;
    for(int i=0;i<G[rt].size();++i){
        dep[G[rt][i]]=dep[rt]+1;
        dfs(G[rt][i]);
        son[rt]+=son[G[rt][i]];
    }
}

int main(){
//    ifstream cin("in.txt");

    int n;cin>>n;
    for(int i=2;i<=n;++i){
        cin>>par[i];
        G[par[i]].push_back(i);
    }

    dfs(1);
    for(int i=1;i<=n;++i)
        printf("%.1f ",dep[i]+(n-son[i]-dep[i])*1.0/2+1);
    cout<<endl;
    return 0;
}


