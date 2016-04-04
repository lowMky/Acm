/*
ID: onlyazh1
LANG: C++
TASK: GGS-DDU
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<algorithm>

using namespace std;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int maxn=5010;
int C[maxn];
int V[maxn];
pair<int,int> P[maxn];
int dp[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++)
            scanf("%d",&V[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&C[i]);
        ll l=V[1],r=V[n];
        int li=1,ri=n,cnt=0;
        while(li<ri){
            if(l==r){
               P[++cnt].first=li;
               P[cnt].second=ri;
               l+=V[++li];r+=V[--ri];
            }
            else if(l<r)
                l+=V[++li];
            else r+=V[--ri];
        }
        if(cnt==0){
            cout<<C[n]<<endl;
            continue;
        }
        dp[0]=0;P[0].first=0;P[0].second=n+1;
        for(int i=1;i<=cnt;i++)
                dp[i]=C[P[i].first]+C[n-P[i].second+1];
        //cout<<dp[1]<<endl;
        for(int i=0;i<=cnt;i++)
            for(int j=i+1;j<=cnt;j++)
                dp[j]=min(dp[i]+C[P[j].first-P[i].first]+C[P[i].second-P[j].second],dp[j]);
        int ans=C[n];
        for(int i=0;i<=cnt;i++)
            ans=min(ans,dp[i]+C[P[i].second-P[i].first-1]);
        cout<<ans<<endl;
    }
    return 0;
}
