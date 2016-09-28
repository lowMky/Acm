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


const int maxn=50100;
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

ll sum[maxn+10];
ll cal(int n,int m){
    ll ret=0;
    if(n>m) swap(n,m);

    for(int i=1,la=0;i<=n;i=la+1){
        la=min(n/(n/i),m/(m/i));
        ret += (sum[la] - sum[i-1])*(n/i)*(m/i);
    }
    return ret;
}


int main(){
//    ifstream cin("in.txt");
    Moblus();
    sum[0]=0;
    for(int i=1;i<maxn;++i)
        sum[i]=sum[i-1]+mu[i];

    int T;scanf("%d",&T);
    int a,b,c,d,k;
    while(T--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("%lld\n",cal(b/k,d/k)-cal((a-1)/k,d/k)-cal(b/k,(c-1)/k)+cal((a-1)/k,(c-1)/k));
    }
    return 0;
}
