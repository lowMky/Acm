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


const int maxn=1e7+100;

/*
bool check[maxn+10];
int prime[maxn+10];

ll mu[maxn+10];

void Moblus(){
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;++i){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }

        for(int j=0;j<tot;++j){
            if(i*prime[j]>maxn) break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}
*/


bool check[maxn+10];
int phi[maxn+10];
int prime[maxn+10];
ll sum[maxn+10];
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
    sum[1]=1;
    for(int i=2;i<=n;++i)
        sum[i]=sum[i-1]+phi[i]*2;
}

ll solve(int n){
    ll ret=0;
    for(int i=0;i<tot&&prime[i]<=n;++i)
        ret+=sum[n/prime[i]];
    return ret;
}


int main(){
//    ifstream cin("in.txt");

    phi_and_prime_table((1e7)+10);
    int T,n;
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",solve(n));
    return 0;
}
