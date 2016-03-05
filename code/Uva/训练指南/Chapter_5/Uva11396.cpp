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

const int maxn=350;
const int maxm=350*350;
struct Edge{
    int v,nex;
}edge[maxm<<1];
int head[maxn],tot;
int col[maxn];
void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}
bool dfs(int u){
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].v;
        if(col[v]==col[u]) return false;
        if(!col[v]){
            col[v]=3-col[u];
            if(!dfs(v)) return false;
        }
    }
    return true;
}

int main(){
    //ifstream cin("in.txt");
    int n;
    while(cin>>n&&n){
        tot=0;
        memset(head,-1,sizeof(head));
        memset(col,0,sizeof(col));
        int u,v;
        while(cin>>u>>v){
            if(u==0&&v==0) break;
            addedge(u,v);
            addedge(v,u);
        }
        bool ans=true;
        for(int i=1;i<=n;i++)
            if(!col[i]){
                col[i]=1;ans=dfs(i);
                if(!ans) break;
            }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

