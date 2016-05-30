#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll MOD=1e9+7;


ll dp[60][60];
int len;
int num[60];


ll dfs(int idx,int cnt,bool e){

    if(cnt<0) return 0;
    if(idx==-1) return cnt==0;
    if(!e&&~dp[idx][cnt])
        return dp[idx][cnt];

    ll res=0;
    int u=(e?num[idx]:1);
    for(int i=0;i<=u;++i)
        res+=dfs(idx-1,cnt-i,e&&i==u);
    return e?res:dp[idx][cnt]=res;
}

void getNum(ll x){
    len=0;
    while(x){
        num[len++]=x%2;
        x>>=1;
    }
}

int main(){
//    ifstream cin("in.txt");

    ll n,t;
    cin>>n>>t;
    int cnt=-1;
    for(int i=0;i<60;++i)
        if((1ll<<i)==t){
            cnt=i;break;
        }
    if(cnt==-1){
        cout<<0<<endl;
        return 0;
    }

    getNum(n+1);
    memset(dp,-1,sizeof(dp));


    cout<<dfs(len-1,cnt+1,true)-(t==1)<<endl;
    return 0;
}
