#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll MOD=1e9+7;

double dp[55][55][55];
double C[55];
int len[55];
int n,p;

void F(int idx){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=n;++i){
        dp[i][0][0]=1;
        for(int j=1;j<=i;++j)
            for(int k=0;k<=p;++k){
                dp[i][j][k]+=dp[i-1][j][k];
                if(k>=len[i]&&i!=idx) dp[i][j][k]+=dp[i-1][j-1][k-len[i]];
            }
    }
}

void F2(){
    C[0]=1.0;
    for(int i=1;i<=n;++i)
        C[i]=C[i-1]*i;
}

int main(){
//    freopen("in.txt","r",stdin);
    int sumlen=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&len[i]);
        sumlen+=len[i];
    }
    scanf("%d",&p);
    F2();
//    F(0);
//    cout<<dp[1][1][1]<<endl;
//    for(int i=0;i<=n;++i,cout<<endl)
//        for(int j=0;j<=n;++j)
//            cout<<dp[n][i][j]<<" ";
    if(sumlen<=p){
        printf("%.5f\n",n*1.0);
        return 0;
    }
    double ans=0;
    for(int i=1;i<=n;++i){
        F(i);
        for(int x=1;x<=len[i];++x)
            for(int cnt=1;cnt<n;++cnt)
                ans+=cnt*C[cnt]*C[n-cnt-1]*dp[n][cnt][p-len[i]+x];
//        for(int i=0;i<=n;++i,cout<<endl)
//            for(int j=0;j<=n;++j)
//                cout<<dp[n][i][j]<<" ";
//        cout<<"ans="<<ans<<endl;
    }
    ans/=C[n];

    printf("%.6lf\n",ans);
    return 0;
}
