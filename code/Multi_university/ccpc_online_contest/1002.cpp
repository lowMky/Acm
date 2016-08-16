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

const int maxn=310;
const int maxm=200010;
const int inf=1e9;
const ll MOD=2;
const ll M=1e9+7;


vector<int> V[maxn];
int prime[2200];
set<int> S;
set<int>::iterator it;
int a[maxn][maxn];
int x[maxn];

void get_prime(int ul){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=ul;++i){
        if(!prime[i])
            prime[++prime[0]]=i;

        for(int j=1;j<=prime[0]&&prime[j]<=ul/i;++j){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void get_factor(ll x,int idx){
    for(int i=1;i<=prime[0];++i){
        if(x%prime[i]==0){
            int cnt=0;
            while(x%prime[i]==0){
                x/=prime[i];
                cnt++;
            }
            if(cnt%2!=0){
                S.insert(i-1);
                V[i-1].push_back(idx);
            }
            if(x==1) break;
        }
    }
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

ll inv(ll a,ll m){
    if(a==1) return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
int equ,var;

int Gauss(){
    int max_r,col,k;
//    free_num=0;
    for(k=0,col=0;k<equ&&col<var;++k,++col){
        max_r=k;
        for(int i=k+1;i<equ;++i){
            if(abs(a[i][col])>abs(a[max_r][col]))
                max_r=i;
        }

        if(a[max_r][col]==0){
            --k;
//            free_x[free_num++]=col;
            continue;
        }

        if(max_r!=k){
            for(int j=col;j<=var;++j)
                swap(a[k][j],a[max_r][j]);
        }
        for(int i=k+1;i<equ;++i){
            if(a[i][col]!=0){
//                for(int j=col;j<=var;++j)
//                    a[i][j]^=a[k][j];

                int LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                int ta=LCM/abs(a[i][col]);
                int tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0) tb=-tb;
                for(int j=col;j<=var;++j)
                    a[i][j]=((a[i][j]*ta-a[k][j]*tb)%MOD+MOD)%MOD;
            }
        }
    }

    for(int i=k;i<equ;++i)
        if(a[i][col]!=0)
            return -1;

    if(k<var) return var-k;

    for(int i=var-1;i>=0;--i){
//        x[i]=a[i][var];
        int tmp=a[i][var];
        for(int j=i+1;j<var;++j){
//            x[i]^=(a[i][j]&&x[j]);
            if(a[i][j]!=0){
                tmp-=a[i][j]*x[j];
                tmp=(tmp%MOD+MOD)%MOD;
            }
        }
        x[i]=(tmp*inv(a[i][i],MOD))%MOD;
    }
    return 0;
}

ll kpow(ll x,ll n){
    ll ret=1;
    while(n){
        if(n&1) ret=(ret*x)%M;
        x=(x*x)%M;
        n>>=1;
    }
    return ret;
}

void init(){
    S.clear();
    memset(a,0,sizeof(a));
    for(int i=0;i<maxn;++i)
        V[i].clear();
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    get_prime(2000);

    ll x;
    int T,n,icase=0;
    scanf("%d",&T);
    while(T--){

        init();

        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lld",&x);
            get_factor(x,i);
        }

        var=n;
        equ=0;
        for(it=S.begin();it!=S.end();++it){
            int k=(*it);
            for(int i=0;i<V[k].size();++i){
                a[equ][V[k][i]]=1;
            }
            ++equ;
        }
        printf("Case #%d:\n",++icase);
        printf("%lld\n",kpow(2,Gauss())-1);
    }
    return 0;
}
