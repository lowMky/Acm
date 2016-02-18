/*
ID: onlyazh1
LANG: C++
TASK: money
*/
#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;

ll dp[30][10010];
ll val[30];
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("money.in");
    ofstream cout("money.out");
#endif
    int v,n;
    cin>>v>>n;
    for(int i=1;i<=v;i++)
        cin>>val[i];
    for(int i=1;i<=v;i++) dp[i][0]=1;
    //dp[0][0]=1;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=n;j++){
            if(j>=val[i])
                dp[i][j]+=dp[i][j-val[i]];
            dp[i][j]+=dp[i-1][j];
        }
    cout<<dp[v][n]<<endl;
    return 0;
}
