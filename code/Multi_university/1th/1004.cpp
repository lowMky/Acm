#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxm=1100100;
const int maxn=100100;



map<int,int> fac[2];
map<int,ll> cnt;
int a[maxn];
int gg[maxn<<2];
int cc;


int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void PushUP(int rt){
    gg[rt]=gcd(gg[rt<<1],gg[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){
        gg[rt]=a[cc++];
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}

int query(int L,int R,int l,int r,int rt){
    int ret=-1;
    if(L<=l&&r<=R) return gg[rt];

    int m=(l+r)>>1;
    if(L<=m) ret=query(L,R,lson);
    if(R>m){
        if(ret==-1) ret=query(L,R,rson);
        else ret=gcd(ret,query(L,R,rson));
    }
    return ret;
}

int main(){

//    freopen("in.txt","r",stdin);

    int T,icase=0;scanf("%d",&T);
    map<int,int>::iterator it;
    while(T--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        cc=0;
        build(1,n,1);
        cnt.clear();
        fac[0].clear();
        fac[1].clear();
        for(int i=0;i<n;++i){
            fac[!(i&1)].clear();
            fac[!(i&1)][a[i]]=1;

            if(cnt.find(a[i])==cnt.end())
                cnt[a[i]]=1;
            else cnt[a[i]]++;

//            cout<<"i="<<i<<" "<<cnt[1]<<endl;
            for(it=fac[i&1].begin();it!=fac[i&1].end();++it){
                int g=gcd(a[i],it->first);
                if(fac[!(i&1)].find(g)==fac[!(i&1)].end())
                    fac[!(i&1)][g]=it->second;
                else fac[!(i&1)][g]+=(it->second);

                if(cnt.find(g)==cnt.end())
                    cnt[g]=(it->second);
                else cnt[g]+=(it->second);
            }
//            cout<<cnt[1]<<endl;
        }
        int Q,l,r,d;scanf("%d",&Q);
        printf("Case #%d:\n",++icase);
        while(Q--){
            scanf("%d%d",&l,&r);
            d=query(l,r,1,n,1);
            printf("%d %lld\n",d,cnt[d]);
        }
    }
    return 0;
}
