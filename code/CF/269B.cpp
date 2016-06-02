#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=10100;
const ll inf=1e8;
const ll MOD=1e9+7;
pair<double,int> P[maxn];

int dp[maxn];
int n,m;

int main(){
//    freopen("in.txt","r",stdin);

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%lf",&P[i].second,&P[i].first);

    sort(P,P+n);

    for(int i=0;i<n;++i){
        dp[i]=1;
        for(int j=0;j<i;++j){
            if(P[i].second>=P[j].second)
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<n-ans<<endl;
    return 0;
}
