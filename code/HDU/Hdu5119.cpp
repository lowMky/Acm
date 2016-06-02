#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=3000100;
const int inf=0x3f3f3f3f;
const ll MOD=1e9+7;


int dp[2][maxn];
int num[50];
int main(){
//    freopen("in.txt","r",stdin);
    int T,n,m,t,a,b,mx,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        mx=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&num[i]);
            mx=max(mx,num[i]);
        }
        t=0;
        while(mx){
            t++;mx>>=1;
        }

        mx=(1<<t);
        for(int i=0;i<mx;++i)
            dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            a=i%2;b=1-a;t=num[i];
            for(int j=0;j<mx;j++)
                dp[a][t^j]=dp[b][t^j]+dp[b][j];
        }
        ll ans=0;a=n%2;
        for(int i=m;i<mx;++i)
            ans+=dp[a][i];
        printf("Case #%d: %I64d\n",++icase,ans);
    }
    return 0;
}
