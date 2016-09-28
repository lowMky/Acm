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


const int maxn=36000;
int prime[maxn+10];

void Prime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;++i){
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;++j){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int eular(int n,int P){
    int ans=n;
    for(int i=1;i<=prime[0]&&prime[i]*prime[i]<=n;++i){
        if(n%prime[i]==0){
            ans-=ans/prime[i];
            while(n%prime[i]==0)
                n/=prime[i];
        }
    }
    if(n>1) ans-=ans/n;
    return ans%P;
}

int quick_pow(int x,int n,int P){
    int ret=1;
    x%=P;
    while(n){
        if(n&1) ret=(ret*x)%P;
        x=(x*x)%P;
        n>>=1;
    }
    return ret%P;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);
    Prime();
    int T;int n,P;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&P);
        int ans=0;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                ans=(ans+eular(n/i,P)*quick_pow(n,i-1,P))%P;
                if(i*i!=n) ans=(ans+eular(i,P)*quick_pow(n,n/i-1,P))%P;
            }
        }
        printf("%d\n",ans%P);
    }
    return 0;
}
