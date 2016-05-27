/*
ID: onlyazh1
LANG: C++
TASK: test
*/


/*
ID: onlyazh1
LANG: C++
TASK: test
*/

#include<bits/stdc++.h>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long ll;
const int maxn=1000100;

pair<int,int> range[maxn];
vector<int> ques[maxn];
vector<int> G[maxn];
int M[maxn];
int ans[maxn];
int idx,n,m;

int sum[maxn<<2];
int tag[maxn<<2];


void PushUP(int l,int r,int rt){
    if(tag[rt]) sum[rt]=(r-l+1);
    else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void update(int L,int R,int x,int l,int r,int rt){
    if(L<=l&&r<=R){
        tag[rt]+=x;
        if(tag[rt]) sum[rt]=(r-l+1);
        else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        return ;
    }
    int m=(l+r)>>1;
    if(L<=m) update(L,R,x,lson);
    if(R>m) update(L,R,x,rson);
    PushUP(l,r,rt);
}

void dfs(int x,int pre){
    M[x]=++idx;
    range[M[x]].first=idx;
    for(int i=0,sz=G[x].size();i<sz;++i){
        if(G[x][i]==pre) continue;
        dfs(G[x][i],x);
    }
    range[M[x]].second=idx;
}

void work(int x,int pre){
    int L,R;

    for(int i=0;i<ques[x].size();++i){
        L=range[M[ques[x][i]]].first;
        R=range[M[ques[x][i]]].second;
        update(L,R,1,1,n,1);
    }

    ans[x]=max(0,sum[1]-1);
    for(int i=0,sz=G[x].size();i<sz;++i){
        if(G[x][i]==pre) continue;
        work(G[x][i],x);
    }

    for(int i=0;i<ques[x].size();++i){
        L=range[M[ques[x][i]]].first;
        R=range[M[ques[x][i]]].second;
        update(L,R,-1,1,n,1);
    }
}

int main(){
    //freopen("in.txt","r",stdin);

    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1,-1);

    while(m--){
        scanf("%d%d",&u,&v);
        ques[u].push_back(v);ques[u].push_back(u);
        ques[v].push_back(u);ques[v].push_back(v);
    }
    work(1,-1);

    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
