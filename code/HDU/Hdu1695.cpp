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

const int maxn=1000100;
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


int main(){
//    ifstream cin("in.txt");
    Moblus();
    int T,icase=0;
    ll n,m,k;
    cin>>T;
    while(T--){
        cin>>n;cin>>n;
        cin>>m;cin>>m;
        cin>>k;
        if(!k){
            cout<<"Case "<<++icase<<": "<<0<<endl;
            continue;
        }
        if(n>m) swap(n,m);
        ll ans1=0,ans2=0;
        for(int i=1;i<=n/k;++i)
            ans1+=mu[i]*(n/(i*k))*(n/(i*k));
        for(int i=1;i<=n/k;++i)
            ans2+=mu[i]*(n/(i*k))*(m/(i*k));
        cout<<"Case "<<++icase<<": "<<ans2-ans1/2<<endl;
    }
    return 0;
}
