#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<cmath>
#include<set>
#include<map>
#include<time.h>

using namespace std;

typedef long long ll;

const int maxn=100100;
const ll MOD=1e9+7;
const int inf=1e9+7;

int sum[maxn];
int ans[maxn];
int val[maxn];
int lowbit(int x){
    return x&(-x);
}

void add(int x){
    while(x<maxn){
        sum[x]++;
        x+=lowbit(x);
    }
}

int query(int x){
    int ret=0;
    while(x>0){
        ret+=sum[x];
        x-=lowbit(x);
    }
    return ret;
}


int main(){
    int T,icase=0;cin>>T;
    while(T--){
        int n;cin>>n;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;++i)
            cin>>val[i];
        for(int i=n;i>0;--i){
            ans[val[i]]=query(val[i])+i-min(i,val[i]);
            add(val[i]);
        }
        printf("Case #%d: ",++icase);
        for(int i=1;i<=n;++i){
            cout<<ans[i];
            if(i!=n) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
