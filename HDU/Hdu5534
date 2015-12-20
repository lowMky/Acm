/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月12日 星期四 13时48分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int INF=(1<<29);
int val[2100];
int dp[2100];

int solve(int n){
    for(int i=0;i<=n;i++)
        dp[i]=-INF;
    dp[0]=0;
    for(int i=2;i<n;i++){
        for(int j=0;j+i<n;j++)
            dp[i+j-1]=max(dp[i+j-1],dp[j]+val[i]);
    }
    return dp[n-2];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
            cin>>val[i];
        int ans=val[1]*n;
        for(int i=2;i<n;i++)
            val[i]-=val[1];
        cout<<ans+solve(n)<<endl;
    }
    return 0;
}
