#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=300100;
const ll inf=1e8;
const ll MOD=1e9+7;


vector<int> G[maxn];
bool g[maxn];

void Sat(int x){
    int cnt=0;
    for(int i=0,sz=G[x].size();i<sz;++i)
        if(g[x]==g[G[x][i]]) cnt++;
    if(cnt>=2){
        g[x]^=1;
        for(int i=0,sz=G[x].size();i<sz;++i)
            if(g[x]==g[G[x][i]]) Sat(G[x][i]);
    }
}

int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i=1;i<=n;++i)
        Sat(i);
    for(int i=1;i<=n;++i)
        printf("%d",g[i]?1:0);
    printf("\n");
    return 0;
}

