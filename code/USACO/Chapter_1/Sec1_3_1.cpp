/*
ID: onlyazh1
LANG: C++
TASK: milk
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;

struct Farmer{
    ll per,cnt;
    bool operator < (const Farmer & A) const{
        return per<A.per;
    }
};

int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("milk.in");
    ofstream cout("milk.out");
#endif
    Farmer far[5010];
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>far[i].per>>far[i].cnt;
    sort(far,far+m);

    ll ans=0;
    for(int i=0;i<m&&n;i++){
        int t=min(n,far[i].cnt);
        ans+=t*far[i].per;
        n-=t;
    }
    cout<<ans<<endl;
    return 0;
}
