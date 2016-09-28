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


int val[1008];
int dp[1008][1008][3][3];
int main(){
    int T,n,s;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;++i)
            scanf("%d",&val[i]);

        dp[0][0][0][0]=1;
        for(int i=1;i<=n;++i)
            for(int j=0;j<=s;++j)
                for(int a=0;a<=2;++a)
                    for(int b=0;b<=2;++b){
                        dp[i][j][a][b]=0;
                        if(j>=val[i]){
                            dp[i][j][a][b]=(dp[i][j][a][b]+dp[i-1][j-val[i]][a][b])%MOD;
                            if(a) dp[i][j][a][b]=(dp[i][j][a][b]+dp[i-1][j-val[i]][a-1][b])%MOD;
                        }
                        dp[i][j][a][b]=(dp[i][j][a][b]+dp[i-1][j][a][b])%MOD;
                        if(b) dp[i][j][a][b]=(dp[i][j][a][b]+dp[i-1][j][a][b-1])%MOD;
                    }
        ll ans=0;
        for(int i=1;i<=s;++i)
            ans=(ans+dp[n][i][2][2])%MOD;
        printf("%lld\n",(ans*4)%MOD);
    }
    return 0;
}

