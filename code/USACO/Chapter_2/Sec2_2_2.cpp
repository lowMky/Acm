/*
ID: onlyazh1
LANG: C++
TASK: subset
*/

#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

//#define LOCAL
typedef long long ll;
int n;
ll dp[50][1000];
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("subset.in");
    ofstream cout("subset.out");
#endif
    cin>>n;
    if(((1+n)*n/2)%2){
        cout<<"0"<<endl;
        return 0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<1000;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=i) dp[i][j]+=dp[i-1][j-i];
        }
    }
    cout<<dp[n][(1+n)*n/4]/2<<endl;
    return 0;
}
