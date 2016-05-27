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

const int maxn=77800;
const ll MOD=777777777;

int can[3][3];

struct Node{
    ll dp[3][3];
}Tr[maxn<<2];

void PushUP(int rt){
    for(int i=0;i<3;++i)
    for(int j=0;j<3;++j){
        Tr[rt].dp[i][j]=0;
    for(int p=0;p<3;++p)
    for(int q=0;q<3;++q)
    if(can[p][q])
        Tr[rt].dp[i][j]=(Tr[rt].dp[i][j]+(Tr[rt<<1].dp[i][p]*Tr[rt<<1|1].dp[q][j])%MOD)%MOD;
    }
}

void build(int l,int r,int rt){
    if(l==r){
        for(int i=0;i<3;++i)
            Tr[rt].dp[i][i]=1;
        return ;
    }
    int m=(l+r)>>1;
    if(l<=m) build(lson);
    if(r>m) build(rson);
    PushUP(rt);
}

void update(int p,int x,int l,int r,int rt){
    if(l==r){
        for(int i=0;i<3;++i)
            Tr[rt].dp[i][i]=(x==i||x==-1?1:0);
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,x,lson);
    else update(p,x,rson);
    PushUP(rt);
}

ll query(int rt){
    ll ret=0;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            ret+=Tr[rt].dp[i][j];
    return ret%MOD;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            scanf("%d",&can[i][j]);

    build(1,n,1);
    //cout<<query(1)<<endl;
    int p,x;
    while(m--){
        scanf("%d%d",&p,&x);
        x--;
        update(p,x,1,n,1);
        printf("%I64d\n",query(1));
    }
    return 0;
}







