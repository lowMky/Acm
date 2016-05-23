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
const int inf=1e9+7;
const int maxn=30010;
const int maxm=maxn;
struct Edge{
    int u,v,w,nex;
}edge[maxm<<1];

int tot,idx;
int head[maxn];

int ss[maxn];
pair<int,int> rang[maxn];
map<string,int> M;
map<int,int> M2;
bool tag[maxn<<2];
int sum[maxn<<2];

void addedge(int u,int v,int w){
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

void dfs(int x,int val,int pre){
    M2[x]=++idx;
    ss[M2[x]]=val;
    rang[M2[x]].first=idx;
    for(int i=head[x];i!=-1;i=edge[i].nex){
        if(edge[i].v==pre) continue;
        dfs(edge[i].v,val+edge[i].w,x);
    }
    rang[M2[x]].second=idx;
}

void PushUP(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int l,int r,int rt){
    if(tag[rt]){
        int m=(r+l)/2;
        sum[rt<<1]=m-l+1-sum[rt<<1];
        sum[rt<<1|1]=r-m-sum[rt<<1|1];
        tag[rt<<1]^=1;
        tag[rt<<1|1]^=1;
        tag[rt]^=1;
    }
}
void build(int l,int r,int rt){
    tag[rt]=0;
    if(l==r){
        sum[rt]=ss[l]%2;
        return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        sum[rt]=r-l+1-sum[rt];
        tag[rt]^=1;
        return ;
    }
    int m=(r+l)/2;
    PushDown(l,r,rt);
    if(L<=m) update(L,R,lson);
    if(R>m) update(L,R,rson);
    PushUP(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    int m=(l+r)>>1;
    PushDown(l,r,rt);
    int ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    PushUP(rt);
    return ret;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,icase=0;cin>>T;
    while(T--){
        M.clear();M2.clear();
        int n,w;cin>>n;
        string s1,s2;
        for(int i=1;i<=n;i++){
            cin>>s1;M[s1]=i;
        }

        tot=0;idx=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<n-1;i++){
            cin>>s1>>s2>>w;
            addedge(M[s1],M[s2],w);
            addedge(M[s2],M[s1],w);
        }

        dfs(1,0,-1);
        build(1,n,1);
//        for(int i=1;i<=5;i++)
//            cout<<ss[i]<<endl;
        //cout<<rang[2].first<<" "<<rang[2].second<<endl;
        cout<<"Case #"<<++icase<<":"<<endl;
        int q;cin>>q;
        char op;ll id;
        while(q--){
            cin>>op;
            if(op=='Q'){
                id=query(1,n,1,n,1);
                //cout<<"==="<<id<<endl;
                cout<<(n-id)*id*2<<endl;
            }
            else{
                cin>>id;id=(id-1)*2;
                id=max(M2[edge[id].v],M2[edge[id].u]);
                //cout<<"id="<<id<<" "<<rang[id].first<<" "<<rang[id].second<<endl;
                update(rang[id].first,rang[id].second,1,n,1);
                id=query(1,n,1,n,1);
                //cout<<"id="<<id<<endl;
            }
        }
    }
    return 0;
}
