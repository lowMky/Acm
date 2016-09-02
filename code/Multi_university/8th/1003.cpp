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

const int maxn=(1<<19)+10;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;

char mp[20][20];
ll dp[maxn];
bool vis[maxn];

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,m,k,n,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;++i)
            scanf("%s",mp[i]);
        for(int i=1;i<(1<<n);++i){
            for(int j=0;j<n;++j){
                if(!(i&(1<<j))) continue;
                for(int k=0;k<n;++k){
                    if(!(i&(1<<k))) continue;
                    if(mp[j][k]=='1'){
                        vis[i]=true;
                        break;
                    }
                }
                if(vis[i]) break;
            }
        }

        dp[0]=0;
        for(int s=1;s<(1<<n);++s){
            dp[s]=inf;
            for(int s0=s;s0;s0=(s0-1)&s){
                if(!vis[s0])
                    dp[s]=min(dp[s],dp[s^s0]+1);
            }
        }
        ll ans=0,f=1;
        for(int i=1;i<(1<<n);++i){
            f*=233;
            ans+=dp[i]*f;
        }
        printf("%u\n",(int)ans);
    }
    return 0;
}
