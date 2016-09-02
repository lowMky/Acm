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

const int maxn=2010;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);
    ll n,m;
    int T,u,v,k,icase=0;
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        ll a=n*(m-1);
        ll b=m*m;
        ll c=gcd(a,b);
        a/=c;b/=c;
        cout<<a<<"/"<<b<<endl;
    }
    return 0;
}
