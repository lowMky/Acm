#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=300100;
const ll inf=1e8;
const ll MOD=1e9+7;

int main(){

    int n,h,t,ans=0;
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        ans++;
        if(t>h) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
