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


const int maxn=1000100;


ll kk[25];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
//    ifstream cin("in.txt");
    int T,n,m,k;
    kk[0]=1;
    for(int i=1;i<25;++i)
        kk[i]=kk[i-1]*3;
    while(scanf("%d",&n)!=EOF){
        if(n==-1) break;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        ll ans=kk[n];
        for(int i=1;i<n;++i)
            ans+=kk[gcd(i,n)];
        if(n%2)
            ans+=kk[(n+1)/2]*n;
        else{
            ans+=kk[n/2+1]*n/2;
            ans+=kk[n/2]*n/2;
        }
        ans/=(n*2);
        printf("%lld\n",ans);
    }
    return 0;
}
