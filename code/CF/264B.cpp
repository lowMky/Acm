#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll MOD=1e9+7;


vector<int> G[maxn];
vector<int> belong[maxn];
int maxa,n,cnt;
int a[maxn];
int prime[maxn];
int idx[maxn];
int dep[maxn];
int tag[maxn];

void getPrime(int maxa){
    for(int i=2;i<=maxa;++i){
        if(!prime[i]){
            prime[++prime[0]]=i;
            idx[i]=prime[0];
        }
        for(int j=1;j<=prime[0]&&prime[j]<=maxa/i;++j){
            prime[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
}
void getFactor(int x){
    int p=x;
//    cout<<p<<endl;
    for(int i=1;i<=prime[0]&&prime[i]<=p/prime[i];++i){
        if(p%prime[i]==0){
//            cout<<"i="<<i<<endl;
            belong[i].push_back(x);
            while(p%prime[i]==0) p/=prime[i];
        }
    }
//    cout<<p<<endl;
    if(p!=1) belong[idx[p]].push_back(x);
}

queue<int> Que;

int main(){
//    freopen("in.txt","r",stdin);

    getPrime(100000);

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        getFactor(a[i]);
        maxa=max(maxa,a[i]);
    }

//    for(int i=1;i<=3;++i){
//        cout<<prime[i]<<" ";
//        for(int j=0;j<belong[i].size();++j)
//            cout<<belong[i][j]<<" ";
//        cout<<endl;
//    }

    for(int i=1;i<=prime[0];++i)
        for(int j=0,sz=belong[i].size();j<sz-1;++j)
            G[belong[i][j]].push_back(belong[i][j+1]);

    memset(tag,false,sizeof(tag));
    for(int i=0;i<n;++i){
        Que.push(a[i]);
        tag[a[i]]=true;
    }

    int now;
    while(!Que.empty()){
        now=Que.front();
        Que.pop();tag[now]=false;
        for(int i=0,sz=G[now].size();i<sz;++i){
            if(dep[G[now][i]]<dep[now]+1){
                dep[G[now][i]]=dep[now]+1;
                if(!tag[G[now][i]]){
                    Que.push(G[now][i]);
                    tag[G[now][i]]=true;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=maxa;++i)
        ans=max(ans,dep[i]);
    cout<<ans+1<<endl;
    return 0;
}
