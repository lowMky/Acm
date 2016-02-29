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

const int MAXN=50005<<1;
const int MAXM=1000010;
int n,m,u,v,tot;
int deg[MAXN];
int low[MAXN];
int dfn[MAXN];
bool cut[MAXN];
int head[MAXN];
int Stack[MAXN];
bool instack[MAXN];
vector<int> belong[MAXN];

int idx,top,block;
struct Edge{
    int v,nex;
}edge[MAXM<<1];

void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

void Tarjan(int u,int pre){
    int son=0;
    low[u]=dfn[u]=++idx;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].v;
        if(v==pre) continue;
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(u==pre) son++;
            if(low[v]>=dfn[u]){
                int vn;block++;
                belong[block].clear();
                do{
                    vn=Stack[--top];
                    belong[block].push_back(vn);
                    instack[vn]=false;
                }while(vn!=v);
                belong[block].push_back(u);
                if(u!=pre) cut[u]=true;
            }
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(u==pre&&son>=2) cut[u]=true;
}

void init(){
    tot=top=idx=block=0;
    memset(deg,0,sizeof(deg));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(head,-1,sizeof(head));
    memset(cut,false,sizeof(cut));
    memset(instack,false,sizeof(instack));
}
int main(){
    //ifstream cin("in.txt");
    int n,icase=0;
    while(cin>>n&&n){
        init();
        int u,v,maxn=0;
        while(n--){
            cin>>u>>v;
            addedge(u,v);
            addedge(v,u);
            maxn=max(maxn,max(u,v));
        }
        for(int i=1;i<=maxn;i++)
            if(!dfn[i]) Tarjan(i,i);
        if(block==1){
            cout<<"Case "<<++icase<<": "<<2<<" "<<ll(maxn)*(maxn-1)/2<<endl;
            continue;
        }
        /*
        for(int i=1;i<=block;i++){
            cout<<belong[i].size()<<endl;
            for(int j=0;j<belong[i].size();j++)
                cout<<belong[i][j]<<" ";
            cout<<endl;
        }
        */
        ll ans1=0,ans2=1;
        for(int i=1;i<=block;i++){
            int cut_cnt=0;
            for(int j=0,sz=belong[i].size();j<sz;j++)
                if(cut[belong[i][j]]) cut_cnt++;
            if(cut_cnt==1){
                ans1++;ans2*=(belong[i].size()-1);
            }
        }
        cout<<"Case "<<++icase<<": "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
