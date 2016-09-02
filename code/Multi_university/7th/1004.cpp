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

const int maxn=1001000;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;

set<int> S;
int cnt[maxn];
int dp[maxn][22];
bool notPrime[maxn];
int prime[maxn];
vector<int> Factor[maxn];

void getPrime(){
    memset(prime,0,sizeof(prime));
    memset(notPrime,false,sizeof(notPrime));
    for(int i=2;i<maxn;++i){
        if(!notPrime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;++j){
            notPrime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void getFactor(){
    int t,tmp;
    cnt[1]=0;
    for(int i=2;i<maxn;++i){
        t=0;tmp=i;
//        cout<<i<<endl;
        for(int j=1;j<=prime[0];++j){
            if(tmp%prime[j]==0){
                while(tmp%prime[j]==0){
                    ++t;tmp/=prime[j];
                }
            }
            if(tmp==1) break;
            if(!notPrime[tmp]){
                tmp=1;++t;
            }
        }
        cnt[i]=t;
    }
}

//void getDivisor(){
//    for(int i=1;i<maxn;++i){
//        for(int j=1;i*j<maxn;++j)
//            Factor[i*j].push_back(i);
//    }
//}

void getDivisor(int x){
    for(int i=1;i*i<=x;++i){
        if(x%i==0){
            Factor[x].push_back(i);
            if(i*i!=x)
                Factor[x].push_back(x/i);
        }
    }
}

void Insert(int x){
    if(!Factor[x].size()) getDivisor(x);
    for(int i=0;i<Factor[x].size();++i)
        ++dp[Factor[x][i]][cnt[x/Factor[x][i]]];
}

void Delete(int x){
    if(!Factor[x].size()) getDivisor(x);
    for(int i=0;i<Factor[x].size();++i)
        --dp[Factor[x][i]][cnt[x/Factor[x][i]]];
}

int query(int x){
    int res=inf;
    if(!Factor[x].size()) getDivisor(x);
    for(int i=0;i<Factor[x].size();++i)
        for(int j=0;j<=20;++j)
            if(dp[Factor[x][i]][j])
                res=min(res,cnt[x/Factor[x][i]]+j);
    return res;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    getPrime();
//        cout<<"***"<<endl;
    getFactor();
//        cout<<"***"<<endl;
//    getDivisor();
//        cout<<"***"<<endl;
    char op;
    int T,n,m,x,u,v,k,icase=0;
    while(scanf("%d\n",&n)&&n){
        printf("Case #%d:\n",++icase);
        while(n--){
            scanf("%c %d\n",&op,&x);
            if(op=='I'){
                if(S.find(x)==S.end()){
                    Insert(x);
                    S.insert(x);
                }
            }
            else if(op=='D'){
                if(S.find(x)!=S.end()){
                    Delete(x);
                    S.erase(x);
                }
            }
            else{
                if(S.empty()) printf("-1\n");
                else printf("%d\n",query(x));
            }
        }
        for(set<int>::iterator it=S.begin();it!=S.end();++it)
            Delete(*it);
        S.clear();
    }
    return 0;
}
