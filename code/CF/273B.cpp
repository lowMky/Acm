#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

struct Node{
    int x,y;
    bool operator < (const Node & A) const{
        if(x==A.x) return y<A.y;
        else return x<A.x;
    }
}P[maxn<<1];

int main(){
//    freopen("in.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n*2;++i){
        scanf("%d",&P[i].x);
        P[i].y=(i%n)+1;
    }
    sort(P,P+n*2);

    int cnt=0;
    for(int i=1;i<n*2;++i)
        if(P[i].x==P[i-1].x&&P[i].y==P[i-1].y)
            cnt++;
    ll ans=1,M,t=0,tmp;
    scanf("%I64d",&M);

    for(int i=0;i<n*2;++i){
        if(!i||P[i].x==P[i-1].x)
            t++;
        else{
            tmp=1;
            for(int k=1;k<=t;++k){
                if(k%2==0&&cnt){
                    tmp=tmp*(k/2)%M;
                    cnt--;
                }
                else tmp=tmp*k%M;
            }
            ans=ans*tmp%M;
            t=1;
        }
    }

    tmp=1;
    for(int k=1;k<=t;++k){
        if(k%2==0&&cnt){
            tmp=tmp*(k/2)%M;
            cnt--;
        }
        else tmp=tmp*k%M;
    }
    ans=ans*tmp%M;
    printf("%I64d\n",ans);
    return 0;
}
