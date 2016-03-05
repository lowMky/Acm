/*
ID: onlyazh1
LANG: C++
TASK: Bring Them There
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
const int maxn=80;
int n,m;
vector<int> G[maxn];
bool mark[maxn<<1];
int S[maxn<<1],c;

bool dfs(int x){
    if(mark[x^1]) return false;
    if(mark[x]) return true;
    mark[x]=true;
    S[c++]=x;
    for(int i=0;i<G[x].size();i++)
        if(!dfs(G[x][i])) return false;
    return true;
}

void add_caluse(int x,int y,int xval,int yval){
    x=x*2+xval;y=y*2+yval;
    G[x^1].push_back(y);
    G[y^1].push_back(x);
}

bool solve(){
    for(int i=0;i<n*2;i+=2)
        if(!mark[i]&&!mark[i+1]){
            c=0;
            if(!dfs(i)){
                if(i==0) return false;
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i+1)) return false;
            }
        }
    return true;
}

int main(){
    //ifstream cin("in.txt");
    while(cin>>n>>m&&n+m){
        for(int i=0;i<n*2;i++) G[i].clear();
        memset(mark,false,sizeof(mark));
        int u,v;char s1,s2;
        int uval,vval;
        while(m--){
            cin>>u>>s1>>v>>s2;
            uval=s1=='h'?1:0;
            vval=s2=='h'?1:0;
            add_caluse(u,v,uval,vval);
        }
        if(!solve()) cout<<"bad luck"<<endl;
        else{
            for(int i=2;i<2*n;i+=2){
                cout<<i/2<<(mark[i]?'w':'h');
                cout<<(i!=2*(n-1)?' ':'\n');
            }
        }
    }
    return 0;
}

