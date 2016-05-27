#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll MOD=1e9+7;

int val[maxn];
ll cnt[maxn];

ll qpow(ll x,ll cnt){
//    cout<<x<<" "<<cnt<<endl;
    ll ret=1;
    while(cnt){
        if(cnt&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        cnt>>=1;
    }
    return ret%MOD;
}

void getFactor(int x,vector<int> & V){
    V.clear();
    for(int i=1;i*i<=x;++i)
        if(x%i==0){
            V.push_back(i);
            if(i!=x/i)
                V.push_back(x/i);
        }
}

vector<int> V;

int main()
{
//    freopen("in.txt","r",stdin);
    int n,maxx=0;scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&val[i]);
        cnt[val[i]]++;
        maxx=max(maxx,val[i]);
    }

//    cout<<maxx<<endl;

    for(int i=maxx-1;i>=0;--i)
        cnt[i]+=cnt[i+1];

    ll ans=1,tmp;
    for(int i=2;i<=maxx;++i){
        tmp=0;
        getFactor(i,V);
//        cout<<"i="<<i<<endl;
        sort(V.begin(),V.end());
//        cout<<V.size()<<endl;
        tmp=qpow(V.size(),cnt[i]);
        tmp=(tmp+MOD-qpow(V.size()-1,cnt[i]))%MOD;
//        cout<<"tmp="<<tmp<<endl;
        for(int j=0,sz=V.size();j<sz-1;++j)
            tmp=(tmp*(qpow(j+1,cnt[V[j]]-cnt[V[j+1]])))%MOD;
        ans=(ans+tmp)%MOD;
//        cout<<"ans="<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
