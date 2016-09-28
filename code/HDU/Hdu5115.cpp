#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

ll dp[220][220];
int s[220];
int main(){
//    freopen("in.txt","r",stdin);

    int T,n,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;++i){
            scanf("%d",&s[0]);
            ans+=s[0];
        }
        s[0]=s[n+1]=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&s[i]);

        for(int i=1;i<=n;++i){
            for(int l=1;l+i<=n+1;++l){
                int r=l+i-1;
                int res=s[l-1]+s[r+1];
                dp[l][r]=min(dp[l+1][r],dp[l][r-1])+res;
                for(int k=l+1;k<r;++k)
                    dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+res);
            }
        }
        printf("Case #%d: %I64d\n",++icase,ans+dp[1][n]);
    }
    return 0;
}
