#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=3000100;
const int inf=0x3f3f3f3f;
const ll MOD=1e9+7;

int cc[30];
int G[50];
int N,M,K,flag;
bool dfs(int idx){
    if(flag) return true;
    if(idx==N*M){
        return flag=true;
    }

    int id=1;
    for(int i=2;i<=K;++i)
        if(cc[id]<cc[i])
            id=i;
    if(cc[id]>(N*M-idx+1)/2)
        return false;

    for(int i=1;i<=K;++i){
        if(!cc[i]||(idx>=M&&i==G[idx-M])||((idx%M)&&i==G[idx-1]))
            continue;
        G[idx]=i;cc[i]--;
//        cout<<"idx="<<idx<<" i="<<i<<endl;
        if(dfs(idx+1)) return true;
        cc[i]++;
    }
    return false;
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T,icase=0;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=K;++i)
            scanf("%d",&cc[i]);
        flag=false;
        printf("Case #%d:\n",++icase);
        if(dfs(0)){
            printf("YES\n");
            for(int i=0;i<N*M;i++){
                printf("%d",G[i]);
                printf(i%M==M-1?"\n":" ");
            }
        }
        else printf("NO\n");
    }
    return 0;
}
