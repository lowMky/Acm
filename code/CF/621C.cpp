/*
ID: onlyazh1
LANG: C++
TASK: test
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
double p[200100];
int main(){
    //ifstream cin("in.txt");
    int MOD;
    int n;cin>>n>>MOD;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ll t=y/MOD-(x-1)/MOD;
        p[i]=t*1.0/(y-x+1);
    }
    double ans=0;
    for(int i=0;i<n;i++)
        ans+=2*(p[i]+p[(i+1)%n]-p[i]*p[(i+1)%n]);
    printf("%.10f\n",ans*1000);
    return 0;
}
