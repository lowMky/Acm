#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll inf=1e18;
const int MOD=1e9;

int main(){
//    ifstream cin("in.txt");

    int t,s,x;
    cin>>t>>s>>x;
    if(x<t||x==t+1) cout<<"NO"<<endl;
    else if((x-t)%s==0||(x-t)%s==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}


