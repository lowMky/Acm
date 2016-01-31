/*
ID: onlyazh1
LANG: C++
TASK: 618D
*/

#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
char M[600][600];
ll dp[2][600][600];

const ll MOD=5201314;
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++)
            cin>>M[i];
        dp[0][0][n-1]=(M[1][0]==M[n][n-1]);
        for(int i=1;i<n;i++){
            memset(dp[i%2],0,sizeof(dp[i%2]));
            for(int x1=0;x1<=i;x1++)
                for(int x2=n-1;x2>=n-i-1;x2--){
                    int y1=i-x1+1;
                    int y2=2*n-i-x2-1;
                    if(M[y1][x1]!=M[y2][x2])
                        continue;
                    //cout<<"***"<<endl;
                    dp[i%2][x1][x2]=(dp[i%2][x1][x2]+dp[!(i%2)][x1-1][x2])%MOD;
                    dp[i%2][x1][x2]=(dp[i%2][x1][x2]+dp[!(i%2)][x1-1][x2+1])%MOD;
                    dp[i%2][x1][x2]=(dp[i%2][x1][x2]+dp[!(i%2)][x1][x2])%MOD;
                    dp[i%2][x1][x2]=(dp[i%2][x1][x2]+dp[!(i%2)][x1][x2+1])%MOD;
                }
        }
        ll ans=0;
        for(int i=0;i<n;i++)
            ans=(ans+dp[(n-1)%2][i][i])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
