#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;

const int inf=1e9;
const int MOD=1e9+7;
const int maxn=1010;
const int maxm=30010;

struct Edge{
    int u,v,w,nex;
    int cut;
}edge[maxm<<2];
int tot,head[maxn];

void addedge(int u,int v,int w){
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

int S,T,del;
bool vis[maxn];
vector<int> inrood,roodtmp;
bool dfs(int x,int par,vector<int> &inrood){
    if(x==T) return true;
    vis[x]=true;

    bool flag=false;
    for(int i=head[x];i!=-1;i=edge[i].nex){
        if(edge[i].v==par) continue;
        if(vis[edge[i].v]) continue;
        if(i==del||(i^1)==del)
            continue;
        if(dfs(edge[i].v,x,inrood)){
            flag=true;
            inrood.push_back(i/2);
        }
    }
    return flag;
}


int low[maxn];
int dfn[maxn];
int Stack[maxn];
int belong[maxn];
bool instack[maxn];
int index,top,block;

void Tarjan(int u,int pare){
//    cout<<u<<endl;
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        v=edge[i].v;
        if((i^1)==pare) continue;
        if(i==del||(i^1)==del)
            continue;
        if(dfn[v]==-1){
            Tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
//                cout<<"i="<<i<<" "<<(i^1)<<endl;
                edge[i].cut=edge[i^1].cut=true;
            }
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }

    if(low[u]==dfn[u]){
        block++;
        do{
            v=Stack[--top];
            instack[v]=false;
            belong[v]=block;
        }while(v!=u);
    }
}

int main(){
//    ifstream cin("in.txt");

    tot=0;
    memset(head,-1,sizeof(head));

    int n,m,u,v,w;
    cin>>n>>m;
    cin>>S>>T;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    del=-1;

    memset(vis,false,sizeof(vis));
    if(!dfs(S,S,inrood)){
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        return 0;
    }

    int tag=-1;
    int ansd[2];
    int ans=2*inf+5;
    for(int p=0;p<inrood.size();++p){
        int i=inrood[p];
        del=i*2;
        roodtmp.clear();
        memset(vis,false,sizeof(vis));
        if(!dfs(S,S,roodtmp)){
            if(ans>edge[i*2].w){
                tag=1;
                ans=edge[i*2].w;
                ansd[0]=i+1;
//                cout<<"ans="<<ans<<endl;
            }
            continue;
        }
        block=top=index=0;
        memset(dfn,-1,sizeof(dfn));
        memset(belong,-1,sizeof(belong));
        memset(instack,false,sizeof(instack));

        for(int j=0;j<2*m;++j)
            edge[j].cut=false;
//        cout<<"***"<<endl;
        Tarjan(S,-1);
//        cout<<"i="<<i<<" "<<belong[S]<<" "<<belong[T]<<endl;
        if(belong[S]==belong[T])
            continue;
        for(int q=0;q<roodtmp.size();++q){
            int j=roodtmp[q];
            if(i==j) continue;
            if(edge[j*2].cut){
                if(ans>edge[i*2].w+edge[j*2].w){
//                    cout<<"j*2="<<j*2<<endl;
//                    cout<<"edge="<<edge[i*2].w+edge[j*2].w<<endl;
                    tag=2;
                    ansd[0]=i+1;ansd[1]=j+1;
                    ans=edge[i*2].w+edge[j*2].w;
                }
            }
        }
//        cout<<"i="<<i<<" "<<ansd[0]<<" "<<ansd[1]<<" "<<ans<<endl;
    }
    if(tag==-1)
        cout<<"-1"<<endl;
    else{
        cout<<ans<<endl;
        cout<<tag<<endl;
        for(int i=0;i<tag;++i)
            cout<<ansd[i]<<" ";
        cout<<endl;
    }
    return 0;
}
