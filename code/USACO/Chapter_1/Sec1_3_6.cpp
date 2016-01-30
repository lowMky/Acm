/*
ID: onlyazh1
LANG: C++
TASK: skidesign
*/

#include<set>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;

int n;
int high[1010];
int Solve(int hmax){
    int res=0;
    for(int i=0;i<n;i++){
        if(high[i]>hmax)
            res+=(high[i]-hmax)*(high[i]-hmax);
        else if(high[i]<hmax-17)
            res+=(hmax-17-high[i])*(hmax-17-high[i]);
    }
    return res;
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("skidesign.in");
    ofstream cout("skidesign.out");
#endif
    int ans=0x3f3f3f3f;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>high[i];
    for(int i=1;i<=100;i++)
        ans=min(ans,Solve(i));
    cout<<ans<<endl;
    return 0;
}
