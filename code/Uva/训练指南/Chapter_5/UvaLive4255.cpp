/*
ID: onlyazh1
LANG: C++
TASK: Guess
*/
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;

const int maxn=30;
int n;
int sum[maxn];
int deg[maxn];
vector<int> G[maxn];

void TopSort(){
    int low=-10;
    queue<int> Que;
    for(int i=0;i<=n;i++)
        if(!deg[i]) Que.push(i);
    while(!Que.empty()){
        int x=Que.front();
        Que.pop();
        sum[x]=low;
        for(int u=0,sz=G[x].size();u<sz;u++){
            deg[G[x][u]]--;
            if(!deg[G[x][u]])
                Que.push(G[x][u]);
        }
        low++;
    }
}
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){

        for(int i=0;i<maxn;i++)
            G[i].clear();
        memset(deg,0,sizeof(deg));

        int cnt=0;cin>>n;
        char str[maxn];cin>>str;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                if(str[cnt]=='-'){
                    G[j].push_back(i-1);
                    deg[i-1]++;
                }
                else if(str[cnt]=='+'){
                    G[i-1].push_back(j);
                    deg[j]++;
                }
                cnt++;
            }
        TopSort();
        cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                if(str[cnt]=='0')
                    sum[i-1]=sum[j];
                cnt++;
            }
        for(int i=1;i<=n;i++){
            if(i-1) cout<<" ";
            cout<<sum[i]-sum[i-1];
        }
        cout<<endl;
    }
    return 0;
}
