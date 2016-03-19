/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;
typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100100;

struct Node{
    ll sum;
    ll fibsum;
    bool tag;
}tr[maxn<<2];
ll fib[100];

void PushUp(int rt){
    tr[rt].sum=tr[rt<<1].sum+tr[rt<<1|1].sum;
    tr[rt].fibsum=tr[rt<<1].fibsum+tr[rt<<1|1].fibsum;
}

void PushDown(int rt){
    if(tr[rt].tag){
        tr[rt<<1].sum=tr[rt<<1].fibsum;
        tr[rt<<1|1].sum=tr[rt<<1|1].fibsum;
        tr[rt<<1].tag=tr[rt<<1|1].tag=true;
        tr[rt].tag=false;
    }
}

void build(int l,int r,int rt){
    tr[rt].tag=false;
    if(l==r){
        tr[rt].sum=0;
        tr[rt].fibsum=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);build(rson);
    PushUp(rt);
}


void update(int p,ll x,int l,int r,int rt){
    if(l==r){
        tr[rt].sum+=x;
        tr[rt].fibsum=1;
        for(int i=0;i<=72;i++)
            if(abs(fib[i]-tr[rt].sum)<abs(tr[rt].fibsum-tr[rt].sum))
                tr[rt].fibsum=fib[i];
        tr[rt].tag=false;
        return ;
    }
    int m=(r+l)>>1;
    PushDown(rt);
    if(p<=m) update(p,x,lson);
    else update(p,x,rson);
    PushUp(rt);
}

void update1(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        tr[rt].sum=tr[rt].fibsum;
        tr[rt].tag=true;
        return ;
    }
    PushDown(rt);
    int m=(l+r)>>1;
    if(L<=m) update1(L,R,lson);
    if(R>m) update1(L,R,rson);
    PushUp(rt);
}

ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tr[rt].sum;
    }
    PushDown(rt);
    int m=(r+l)>>1;
    ll ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}
int main(){
    fib[0]=fib[1]=1;
    for(int i=2;i<=80;i++)
        fib[i]=fib[i-1]+fib[i-2];

    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,n,1);
        int op,l,r,k;ll d;
        while(m--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%I64d",&k,&d);
                update(k,d,1,n,1);
            }
            else if(op==2){
                scanf("%d%d",&l,&r);
                printf("%I64d\n",query(l,r,1,n,1));
            }
            else{
                scanf("%d%d",&l,&r);
                update1(l,r,1,n,1);
            }
        }
    }
    return 0;
}
