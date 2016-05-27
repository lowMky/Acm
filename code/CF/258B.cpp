#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll MOD=1e9+7;

int len;
int num[20];
ll dp[20][20];
ll res[20];

void getNum(ll x){
    len=0;
    while(x){
        num[++len]=x%10;
        x/=10;
    }
}

ll F(int idx,int cnt,bool e){
    if(!idx) return cnt==0;
    if(!e&&dp[idx][cnt]!=-1) return dp[idx][cnt];

    int limit=e?num[idx]:9;
    ll ret=0;
    for(int i=0;i<=limit;++i){
        if(i==4||i==7)
            ret=(ret+F(idx-1,cnt-1,e&&i==limit))%MOD;
        else ret=(ret+F(idx-1,cnt,e&&i==limit))%MOD;
    }
    return e?ret:dp[idx][cnt]=ret;
}


ll dfs(int idx,int cnt){
    if(idx==6) return 1;
    ll ret=0;
    for(int i=0;i<=cnt;++i){
        res[i]--;
        ret=(ret+(res[i]+1)*dfs(idx+1,cnt-i))%MOD;
        res[i]++;
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    ll x;scanf("%I64d",&x);
    if(x<=7){
        cout<<0<<endl;return 0;
    }
    getNum(x);
//    cout<<len<<endl;
    F(len,len,true);
    for(int i=0;i<=len;++i){
        memset(dp,-1,sizeof(dp));
        res[i]=F(len,i,true);
//        res[i]=dp[len][i];
    }
    res[0]--;
//    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
    ll ans=0;
    for(int i=1;i<=len;++i)
        ans=(ans+res[i]*dfs(0,i-1))%MOD;
    cout<<ans<<endl;
    return 0;
}
