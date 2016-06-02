#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;
pair<ll,ll> P[maxn];
int main(){
    int n;scanf("%d",&n);
    ll k,prek,c,prec;
    for(int i=0;i<n;++i)
        scanf("%I64d%I64d",&P[i].first,&P[i].second);
    sort(P,P+n);

//    for(int i=1;i<n;i++){
//        k=P[i].first;c=P[i].second;
//        prek=P[i-1].first;prec=P[i-1].second;
////        cout<<prek<<prec<<k<<c<<endl;
////        cout<<prec/(1<<((k-prek)*2))<<" "<<(prec%(1<<((k-prek)*2))?1:0)<<endl;
//        if(k-prek>=25) continue;
//        else
//            P[i].second=max(P[i].second,prec/(1ll<<((k-prek)*2))+(prec%(1ll<<((k-prek)*2))?1ll:0ll));
//    }

//    ll ans=P[n-1].first;
//    while(P[n-1].second>1){
//        ans++;
//        P[n-1].second=P[n-1].second/4+(P[n-1].second%4?1ll:0ll);
//    }

    ll ans=0;
    for(int i=0;i<n;++i){
        k=P[i].first;
        c=P[i].second;
        if(c==1)
            k++;
        else while(c>1){
            k++;
            c=c/4+(c%4?1ll:0ll);
        }
        ans=max(ans,k);
    }
    printf("%I64d\n",ans);
    return 0;
}
