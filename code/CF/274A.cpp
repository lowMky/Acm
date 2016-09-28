#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const ll inf=1e8;
const ll MOD=1e9+7;

set<int> S;
int cc[maxn];
int main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>cc[i];

    sort(cc,cc+n);

    for(int i=0;i<n;++i)
        if(cc[i]%k!=0||S.find(cc[i]/k)==S.end())
            S.insert(cc[i]);

    cout<<(int)S.size()<<endl;
    return 0;
}
