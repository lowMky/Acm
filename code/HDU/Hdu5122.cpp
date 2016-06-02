#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int inf=0x3f3f3f3f;
const ll MOD=1e9+7;

int sum[maxn];

int lowbit(int x){
    return x&(-x);
}
void add(int x){
    while(x<maxn){
        sum[x]++;
        x+=lowbit(x);
    }
}

int query(int x){
    int ret=0;
    while(x>0){
        ret+=sum[x];
        x-=lowbit(x);
    }
    return ret;
}
int main(){
    int T,n,t,ans,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        ans=0;
        for(int i=0;i<n;++i){
            scanf("%d",&t);
            if(query(t-1)<t-1)
                ans++;
            add(t);
        }
        printf("Case #%d: %d\n",++icase,ans);
    }
    return 0;
}
