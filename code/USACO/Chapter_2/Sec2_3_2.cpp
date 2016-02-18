/*
ID: onlyazh1
LANG: C++
TASK: nocows
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;
const int M=9901;
int dp[300][200];
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("nocows.in");
    ofstream cout("nocows.out");
#endif

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=i-2;k++)
                dp[i][j]=(dp[i][j]%M+dp[k][j-1]*dp[i-1-k][j-1]%M)%M;

    cout<<(dp[n][m]-dp[n][m-1]+M)%M<<endl;
    return 0;
}
