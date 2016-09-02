#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int maxm=1000100;
const int maxn=100010;

int a[20];

bool G[12][12];
bool GG[12][12];
int n,m;
bool used[12];
int linker[12];
bool dfs(int u){
    for(int v=1;v<=n;++v)
        if(G[u][v]&&!used[v]){
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    return false;
}

int hungary(){
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=1;u<=n;++u){
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
//    cout<<"res="<<res<<endl;
    return n-res;
}

int main(){
//    freopen("in.txt","r",stdin);

    while(scanf("%d%d",&n,&m)!=EOF){
        int u,v,ans=9;
        for(int i=1;i<=n;++i)
            a[i]=i;
        memset(GG,false,sizeof(GG));
        for(int i=0;i<m;++i){
            scanf("%d%d",&u,&v);
            GG[v][u]=true;
        }


//        for(int i=1;i<=n;++i,cout<<endl)
//            for(int j=1;j<=n;++j)
//                cout<<(GG[i][j]?1:0)<<" ";

        do{
            memset(G,true,sizeof(G));
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j)
                    if(GG[a[i]][j]){

                        G[j][i]=false;
                        if(i==n) G[j][1]=false;
                        else G[j][i+1]=false;
                    }
            }
//            for(int i=1;i<=n;++i)
//                cout<<a[i]<<" ";
//            cout<<endl;
//
//            for(int i=1;i<=n;++i,cout<<endl)
//                for(int j=1;j<=n;++j)
//                    cout<<(G[i][j]?1:0)<<" ";
            ans=min(ans,hungary());
            if(ans==0) break;
        }while(next_permutation(a+1,a+n+1));
        printf("%d\n",ans);
    }
    return 0;
}
