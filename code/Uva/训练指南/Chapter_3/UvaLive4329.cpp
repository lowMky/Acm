/*
ID: onlyazh1
LANG: C++
TASK: Ping pong
*/

#include<iostream>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<sstream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100100;

int C[maxn];
int l[maxn];
int r[maxn];
int d[maxn];
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int d){
    while(x<maxn){
        C[x]+=d;x+=lowbit(x);
    }
}

int sum(int x){
    int res=0;
    while(x>0){
        res+=C[x];x-=lowbit(x);
    }
    return res;
}
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        memset(C,0,sizeof(C));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            l[i]=sum(d[i]);
            add(d[i],1);
        }
        memset(C,0,sizeof(C));
        for(int i=n;i>0;i--){
            r[i]=sum(d[i]);
            add(d[i],1);
        }

        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=((ll)l[i]*(ll)(n-i-r[i])+(ll)(i-1-l[i])*(ll)r[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
