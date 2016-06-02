#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

ll h[maxn];

int main(){
//    ifstream cin("in.txt");
    ll n,H,K;
    cin>>n>>H>>K;
    for(int i=0;i<n;++i)
        cin>>h[i];

    ll t,rem=0,ans=0;
    for(int i=0;i<n;){
        rem+=h[i];
        if(rem<=H){
            i++;continue;
        }
        rem-=h[i];
        t=(rem+h[i]+K-1-H)/K;
        rem=max(0ll,rem-t*K);
        ans+=t;
    }
    ans+=(rem+K-1)/K;
    cout<<ans<<endl;
    return 0;
}
