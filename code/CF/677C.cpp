#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

char s[100100];

int fun(char ch){
    if('0'<=ch&&ch<='9') return ch-'0';
    if('A'<=ch&&ch<='Z') return 10+ch-'A';
    if('a'<=ch&&ch<='z') return 36+ch-'a';
    if(ch=='-') return 62;
    if(ch=='_') return 63;
}

ll kpow[10];

int main(){
//    ifstream cin("in.txt");
    scanf("%s",s);
    ll ans=1;int t,cnt;
    kpow[0]=1;
    for(int i=1;i<=6;++i)
        kpow[i]=3*kpow[i-1];
    for(int i=0,len=strlen(s);i<len;++i){
        int t=fun(s[i]);
        cnt=0;
        while(t){
            if(t&1) cnt++;
            t>>=1;
        }
        ans=(ans*kpow[6-cnt])%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}
