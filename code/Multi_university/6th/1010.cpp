#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<cstring>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=1001000;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;

ll sum[60];

int dfs(ll p,ll q,int step,int stop){
    if(p<=q) return step+max(0ll,q-p-stop);
    int k=0;
    while(p-sum[k]>q)
        k++;
    if(p-sum[k]==q) return step+k;

    int res=step+k+max(0ll,q-max(0ll,p-sum[k])-stop);
    return min(res,dfs(p-sum[k-1],q,step+k,stop+1));
}

int main(){
    ll res=1;
    sum[1]=1;
    for(int i=2;i<=32;++i){
        res<<=1;
        sum[i]=sum[i-1]+res;
    }

    int T;scanf("%d",&T);
    while(T--){
        ll p,q;
        scanf("%lld%lld",&p,&q);
        if(p<=q) printf("%lld\n",q-p);
        else printf("%d\n",dfs(p,q,0,0));
    }
    return 0;
}



