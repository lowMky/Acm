#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<cstring>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1


const int maxn=1000100;

bool check[maxn+10];
int phi[maxn+10];
int prime[maxn+10];
int tot;

void phi_and_prime_table(int n){
    memset(check,false,sizeof(check));
    tot=0;
    phi[1]=1;
    for(int i=2;i<=n;++i){
        if(!check[i]){
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;++j){
            if(i*prime[j]>n) break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}

ll eular(ll n){
    ll ans=n;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0){
            ans-=ans/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1) ans-=ans/n;
    return ans;
}

int main(){
//    ifstream cin("in.txt");
    int T,m,k;ll n;
    while(scanf("%lld",&n)!=EOF){
        ll ans=0;
        for(ll i=1;i*i<=n;++i){
            if(n%i==0){
                ans+=i*eular(n/i);
                if(i*i!=n) ans+=(n/i)*eular(i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
