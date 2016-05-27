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
const int maxn=1e6+7;


pair<int,int> mx[maxn<<2];
int to[maxn];
ll sum[maxn];
int n;

void PushUP(int rt){
    if(mx[rt<<1].first>=mx[rt<<1|1].first)
        mx[rt]=mx[rt<<1];
    else mx[rt]=mx[rt<<1|1];
}
void update(int p,int x,int l,int r,int rt){
    if(l==r){
        mx[rt].first=x;
        mx[rt].second=l;
        return ;
    }

    int m=(l+r)/2;
    if(p<=m) update(p,x,lson);
    else update(p,x,rson);
    PushUP(rt);
}

pair<int,int> query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return mx[rt];
    }
    int m=(l+r)/2;
    pair<int,int> ret1,ret2;
    ret1.first=ret2.first=-1;
    if(L<=m) ret1=query(L,R,lson);
    if(R>m) ret2=query(L,R,rson);
    return ret1.first>=ret2.first?ret1:ret2;
}

ll add(int x){
    if(x==n) return sum[x]=0;
    pair<int,int> px=query(x,to[x],1,n,1);
    if(px.second==x) return sum[x]=(n-x)+(sum[px.first]==-1?add(px.first):sum[px.first]);
    else return sum[x]=(n-x+px.second-to[x])+(sum[px.second]==-1?add(px.second):sum[px.second]);
}

int main(){

    //ifstream cin("in.txt");

    memset(sum,-1,sizeof(sum));
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>to[i];
        update(i,to[i],1,n,1);
    }
    for(int i=1;i<n;i++){
        if(sum[i]==-1) add(i);
    }
    ll ans=0;
    for(int i=1;i<n;i++)
        ans+=sum[i];
    cout<<ans<<endl;
    return 0;
}
