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

int P,n,m,T;
ll pi[21];
int hurt[21];
ll dp[(1<<20)+10];

int check(int x){
    int can=0;
    for(int i=n;i<n+m;++i)
        if(x&(1<<i)) can+=hurt[i-n];
    return can>=P;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}


int main(){
    pi[0]=pi[1]=1;
    for(int i=2;i<=20;++i)
        pi[i]=pi[i-1]*i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&P,&n,&m);
        for(int i=0;i<m;++i)
            scanf("%d",&hurt[i]);

        ll ans=0;
        int tot=n+m;
        int totA=(1<<n)-1;

        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0,left,haveA,have;i<(1<<tot);++i){
            have=__builtin_popcount(i);
            haveA=__builtin_popcount(i&totA);
            left=tot-have;
            if(check(i)){
                ans+=dp[i]*pi[left];
                continue;
            }

            if(haveA*2+1-have<=0) continue;
            for(int j=0;j<tot;++j){
                if(!(i&(1<<j))){
                    dp[i+(1<<j)]+=dp[i];
                }
            }
        }
        ll d=gcd(ans,pi[tot]);
        printf("%lld/%lld\n",ans/d,pi[tot]/d);
    }
    return 0;
}



