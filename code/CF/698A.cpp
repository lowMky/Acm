#include<bits/stdc++.h>

using namespace std;

int dp[110][3];

int main()
{
    int n;cin>>n;
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;++i){
        int tag;cin>>tag;
        if(tag==0){
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][1]=dp[i][2]=1000;
        }
        else if(tag==1){
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=1000;
        }
        else if(tag==2){
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=1000;
        }
        else if(tag==3){
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    int mi=1000;
    mi=min(dp[n][0],min(dp[n][1],dp[n][2]));
    cout<<mi<<endl;
    return 0;
}
