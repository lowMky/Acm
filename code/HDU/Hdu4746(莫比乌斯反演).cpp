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
int prime[maxn+10];
int num[maxn+10];
int mu[maxn+10];
ll cnt[maxn+10][20];

void Moblus(){
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;++i){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
            num[i]=1;
        }

        for(int j=0;j<tot;++j){
            if(i*prime[j]>maxn) break;
            check[i*prime[j]]=true;
            num[i*prime[j]]=num[i]+1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }

    for(int i=1;i<=maxn;++i)
        for(int j=i;j<=maxn;j+=i)
            cnt[j][num[i]]+=mu[j/i];

    for(int i=0;i<=maxn;++i)
        for(int j=1;j<19;++j)
            cnt[i][j]+=cnt[i][j-1];

    for(int i=1;i<=maxn;++i)
        for(int j=0;j<19;++j)
            cnt[i][j]+=cnt[i-1][j];

}


int main(){
//    ifstream cin("in.txt");
    Moblus();
    int T,n,m,k;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        k=min(k,18);
        ll ans=0;
        if(n>m) swap(n,m);
        for(int i=1,last=i;i<=n;i=last+1){
            last=min(n/(n/i),m/(m/i));
            ans+=(ll)(cnt[last][k]-cnt[i-1][k])*(n/i)*(m/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
