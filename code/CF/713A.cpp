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

const int maxn=60100;
const int maxm=200010;
const int inf=1e9;

int cnt[1<<21];

int fun(ll a){
    int m,x;
    m=0;x=0;
    while(a){
        x*=2;
        if(a%2) ++x;
        a/=10;
        ++m;
    }
    int k=0;
    for(int i=m-1;i>=0;--i,x>>=1){
        if(x&1) k+=(1<<i);
    }
    return k;
}

char s[20];

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    char op;
    ll x;
    int T,n,m,tag,u,v,val,W;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        getchar();
        scanf("%c ",&op);
//        cout<<"op="<<op<<endl;
        if(op!='?'){
            scanf("%lld",&x);
//            cout<<"x="<<x<<endl;
            x=fun(x);
//            cout<<"x="<<x<<endl;
            if(op=='+') ++cnt[x];
            else if(op=='-') --cnt[x];
        }
        else{
            bool flag=false;
            x=0;
            scanf("%s",s);
            for(int i=0,len=strlen(s);i<len;++i){
                if(!flag&&s[i]=='0')
                    continue;
                flag=true;
                x<<=1;
                if(s[i]=='1') ++x;
            }
            cout<<cnt[x]<<endl;
        }
    }
    return 0;
}
