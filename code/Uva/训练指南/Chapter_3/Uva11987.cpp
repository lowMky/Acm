/*
ID: onlyazh1
LANG: C++
TASK: Almost Union-Find
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

int par[200100];
int tot[200100];
int sum[200100];
int pid[100100];

void init(int n){
    for(int i=1;i<=200000;i++){
        par[i]=i;
        tot[i]=1;sum[i]=i;
    }
    for(int i=1;i<=n;i++)
        pid[i]=i;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int main(){
    //ifstream cin("in.txt");
    int n,m;
    while(cin>>n>>m){
        init(n);int c=n;
        while(m--){
            int op,u,v;
            cin>>op;
            if(op==1){
                cin>>u>>v;
                u=find(pid[u]);
                v=find(pid[v]);
                if(u==v) continue;
                else{
                    par[v]=u;
                    tot[u]+=tot[v];
                    sum[u]+=sum[v];
                }
            }
            else if(op==2){
                cin>>u>>v;
                int root=find(pid[u]);
                tot[root]--;sum[root]-=u;
                v=find(pid[v]);pid[u]=++c;par[c]=v;
                tot[v]++;sum[v]+=u;
            }
            else{
                cin>>u;u=find(pid[u]);
                cout<<tot[u]<<" "<<sum[u]<<endl;
            }
        }
    }
    return 0;
}
