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
const ll MOD=777777777;

ll S[]={3,15,81,6723,50625,2562991875LL};
ll sg[]={0,1,2,0,3,1,2};

int main(){
    int ans=0,n;
    ll t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t;
        ans^=sg[lower_bound(S,S+6,t)-S];
    }
    if(ans) cout<<"Furlo"<<endl;
    else cout<<"Rublo"<<endl;
    return 0;
}
