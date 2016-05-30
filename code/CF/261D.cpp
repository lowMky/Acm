#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll MOD=1e9+7;


int k,n,maxb,t;
int a[maxn];
int f[maxn];

int main(){
    cin>>k>>n>>maxb>>t;
    t=min(t,maxb);
    while(k--){
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=maxb;++i)
            f[i]=0;
        for(int i=1;i<=t;++i)
            for(int j=1;j<=n;++j){
                f[a[j]]=max(f[a[j]],f[a[j]-1]+1);
                for(int k=a[j]+1;k<=maxb;k++)
                    if(f[a[j]]>f[k]) f[k]=f[a[j]];
                    else break;
            }
        cout<<f[maxb]<<endl;
    }
    return 0;
}
