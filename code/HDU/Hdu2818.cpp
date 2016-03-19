/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
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
typedef long long ll;
const int maxn=30010;
int par[maxn];
int low[maxn];
int cnt[maxn];

int find(int x){
    if(x==par[x])
        return x;
    else{
        int v=find(par[x]);
        if(par[par[x]]!=par[x])
            cnt[x]+=cnt[par[x]];
        return par[x]=v;
    }
}

int main(){
    //ifstream cin("in.txt");
    int p;
    while(cin>>p){
        for(int i=0;i<maxn;i++){
            par[i]=i;low[i]=i;cnt[i]=1;
        }
        while(p--){
            char op;int u,v,x,y;
            cin>>op;
            if(op=='M'){
                cin>>u>>v;
                u=find(u);v=find(v);
                if(u==v) continue;
                par[v]=low[u];
                low[u]=low[v];
            }
            else{
                cin>>u;find(u);
                find(low[par[u]]);
                if(u==par[u]) cout<<(low[par[u]]==u?0:cnt[low[par[u]]]-cnt[u]+1)<<endl;
                else cout<<cnt[low[par[u]]]-cnt[u]<<endl;
            }
        }
    }
    return 0;
}
