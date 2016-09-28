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


const int maxn=500100;

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
    sum[1]=0;
    for(int i=2;i<=n;++i)
        sum[i]=sum[i-1]+phi[i];
}

int main(){
//    ifstream cin("in.txt");
    phi_and_prime_table(40010);
    int T,n,m,k;
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",sum[n-1]*2+3);
    return 0;
}
