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

const int maxn=3010;
const int maxm=200010;
const int inf=1e9;

map<int,ll> M;

ll x[maxn];
ll tmp[maxn];
ll dp[maxn][maxn];

ll labs(ll a){
    return a>0?a:-a;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i];
        x[i]-=(i-1);
        tmp[i]=x[i];
    }

    int cnt=0;
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;++i)
        if(tmp[i]!=tmp[i-1]) M[++cnt]=tmp[i];

    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=cnt;++i)
        dp[0][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=cnt;++j){
            if(j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]);
            dp[i][j]=min(dp[i][j],dp[i-1][j]+labs(M[j]-x[i]));
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    ll ans=1e18;
    for(int i=1;i<=cnt;++i)
        ans=min(ans,dp[n][i]);
    printf("%lld\n",ans);
    return 0;
}
