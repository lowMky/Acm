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

const int maxn=3000100;
const int maxm=2000010;
const int inf=1e9+7;

int idx[maxn];
int dep[maxn];
int ans[maxn];
int s[maxn];
void init(int n,int k){
    int tmp=n,cnt=0;
    while(tmp){
        s[++cnt]=(tmp-1)/k+1;
        tmp-=((tmp-1)/k+1);
    }
    for(int i=1;i<=cnt;++i)
        s[i]+=s[i-1];

    dep[0]=0;idx[0]=1;
    for(int i=1;i<n;++i){
        dep[i]=i%k?dep[i-i/k-1]+1:0;
        idx[i]=i%k?idx[i-i/k-1]:i/k+1;
    }
    for(int i=0;i<n;++i)
        ans[s[dep[i]]+idx[i]]=i+1;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,n,m,icase=0;
    scanf("%d",&T);
    while(T--){
        int q,k;
        scanf("%d%d%d",&n,&k,&q);
        init(n,k);
        while(q--){
            scanf("%d",&u);
            printf("%d\n",ans[u]);
        }
    }
    return 0;
}
