#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e18;
const ll MOD=1e9+7;


ll kpow(ll x,ll n){
    ll ret=1;
    while(n){
        if(n&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return ret;
}

int main(){
//    ifstream cin("in.txt");

    int n;cin>>n;
    ll mi=1,t;bool flag=false;
    for(int i=0;i<n;++i){
        cin>>t;
        if(t%2==0) flag=true;
        mi=(t%(MOD-1)*(mi%(MOD-1)))%(MOD-1);
    }

    ll q=kpow(2,(mi-1+MOD-1)%(MOD-1));
    ll p=((q+(flag?1:-1))*kpow(3,MOD-2))%MOD;

    cout<<p<<"/"<<q<<endl;
    return 0;
}


