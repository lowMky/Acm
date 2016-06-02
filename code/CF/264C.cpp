#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

ll dp[maxn];
int c[maxn];
ll val[maxn];
bool vs[maxn];

int main(){
//    freopen("in.txt","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%I64d",&val[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&c[i]);

    ll a,b;int mxc1,mxc2;
    while(q--){
        scanf("%I64d%I64d",&a,&b);
        for(int i=0;i<=n;++i)
            dp[i]=-inf*inf;
        mxc1=1;mxc2=2;
        for(int i=0;i<n;++i){
            if(mxc1==c[i]){
                dp[c[i]]=max(dp[c[i]],max(dp[c[i]]+a*val[i],dp[mxc2]+b*val[i]));
                dp[c[i]]=max(dp[c[i]],b*val[i]);
            }
            else{
                dp[c[i]]=max(dp[c[i]],max(dp[c[i]]+a*val[i],dp[mxc1]+b*val[i]));
                dp[c[i]]=max(dp[c[i]],b*val[i]);
                if(dp[c[i]]>dp[mxc2]) mxc2=c[i];
                if(dp[mxc2]>dp[mxc1]) swap(mxc1,mxc2);
            }
        }
        ll ans=0;
        cout<<max(0ll,dp[mxc1])<<endl;

    }
    return 0;
}
