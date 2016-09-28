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
const int MOD=9973;
int prime[maxn+10];

int N;

struct Matrix{
    int M[12][12];

    Matrix(){
        memset(M,0,sizeof(M));
    }
};


Matrix mul(Matrix & a,Matrix & b){
    Matrix ret;
    memset(ret.M,0,sizeof(ret.M));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<N;++k){
                ret.M[i][j]=(ret.M[i][j]+a.M[i][k]*b.M[k][j])%MOD;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix & a,int n){
    Matrix ret;
    Matrix x;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            x.M[i][j]=a.M[i][j];
    memset(ret.M,0,sizeof(ret.M));
    for(int i=0;i<N;++i)
        ret.M[i][i]=1;
    while(n){
        if(n&1) ret=mul(ret,x);
        x=mul(x,x);n>>=1;
    }
    return ret;
}

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

int eular(int n){
    int ans=n;
    for(int i=1;i<=prime[0]&&prime[i]*prime[i]<=n;++i){
        if(n%prime[i]==0){
            ans-=ans/prime[i];
            while(n%prime[i]==0)
                n/=prime[i];
        }
    }
    if(n>1) ans-=ans/n;
    return ans%MOD;
}

int sum(Matrix x){
    int ret=0;
    for(int i=0;i<N;++i)
        ret=(ret+x.M[i][i])%MOD;
    return ret;
}

int kpow(int x,int n){
    int ret=1;
    x%=MOD;
    while(n){
        if(n&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return ret;
}

Matrix A;

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);
    Prime();
    int T,n,m,k,u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&N,&k);
        memset(A.M,0,sizeof(A.M));
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                A.M[i][j]=1;
        while(k--){
            scanf("%d%d",&u,&v);
            --u;--v;
            A.M[u][v]=A.M[v][u]=0;
        }
        int ans=0;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                ans=(ans+eular(n/i)*sum(pow(A,i)))%MOD;
                if(i*i!=n) ans=(ans+eular(i)*sum(pow(A,n/i)))%MOD;
            }
        }
        printf("%d\n",(ans*kpow(n,MOD-2))%MOD);
    }
    return 0;
}
