/*
ID: onlyazh1
LANG: C++
TASK: concom
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

int dp[110][110];
bool con[110][110];
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("concom.in");
    ofstream cout("concom.out");
#endif

    int n,m=0;cin>>n;
    int u,v,w;
    while(n--){
        cin>>u>>v>>w;
        dp[u][v]=w;
        m=max(m,max(u,v));
        if(w>50) con[u][v]=true;
    }
    for(int i=1;i<=m;i++){
        con[i][i]=true;
        bool tag=true;
        while(tag){
            tag=false;
            for(int j=1;j<=m;j++){
                if(!con[i][j]){
                    int sum=0;
                    for(int k=1;k<=m;k++)
                        if(con[i][k]) sum+=dp[k][j];
                    if(sum>50){
                        con[i][j]=true;
                        tag=true;
                    }
                }
            }
        }
    }


    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(con[i][j]&&i!=j) cout<<i<<" "<<j<<endl;
    return 0;
}
