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

int main(){
    //freopen("in.txt","r",stdin);
    int T,icase=0;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        double sum=0,k;
        for(int i=0;i<n;++i){
            scanf("%lf",&k);
            sum+=k;
        }
        for(int i=0;i<n;++i)
            scanf("%lf",&k);
        printf("Case #%d: %.6f\n",++icase,(n+1)/sum);

    }
    return 0;
}
