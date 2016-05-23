/*
ID: onlyazh1
LANG: C++
TASK: test
*/

#include<bits/stdc++.h>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long ll;
const int maxn=1010;
const int maxm=100050;
ll sum[maxn];
struct Node{
    int x,y;
    int loc,id;
    bool operator< (const Node &A)const{
        return y*1.0/x<A.y*1.0/A.x;
    }
}node[maxm];

int lowbit(int x){
    return x&(-x);
}

void add(int x,ll p){
    while(x<maxn){
        sum[x]+=p;
        x+=lowbit(x);
    }
}

ll query(int x){
    ll ret=0;
    while(x>0){
        ret+=sum[x];
        x-=lowbit(x);
    }
    return ret;
}

int hi[maxn];
ll ans[maxm];

int main(){
    //ifstream cin("in.txt");
    int T,icase=0;scanf("%d",&T);
    while(T--){
        for(int i=0;i<maxn;i++){
            hi[i]=1;
            sum[i]=0;
        }
        ll A,B;
        scanf("%lld%lld",&A,&B);
        int q;cin>>q;
        for(int i=0;i<q;++i){
            scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].loc);
            node[i].id=i;
        }
        sort(node,node+q);
        for(int i=0;i<q;i++){
            for(int j=1;j<=1000&&hi[j]<=1000;j++)
                while(hi[j]<=1000&&hi[j]*node[i].x<=j*node[i].y){
                    add(j,(j+A)*(hi[j]+B));hi[j]++;
                }
            ans[node[i].id]=query(node[i].loc);
        }
        printf("Case #%d:\n",++icase);
        for(int i=0;i<q;i++)
            printf("%lld\n",ans[i]);
    }
    return 0;
}
