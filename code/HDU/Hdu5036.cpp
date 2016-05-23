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

bitset<1010> G[1010];
int cnt[1010];

int main(){
    //freopen("in.txt","r",stdin);
    int T,icase=0;scanf("%d",&T);
    while(T--){
        int n,k,t;scanf("%d",&n);
        for(int i=0;i<n;i++){
            G[i].reset();
            G[i][i]=true;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&t);
                G[i][--t]=true;
            }
        }

        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(G[j][i])
                    G[j]|=G[i];

        double ans=0;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++)
                if(G[j][i]) tmp++;
            ans+=1.0/tmp;
        }
        printf("Case #%d: %.5f\n",++icase,ans);
    }
    return 0;
}
