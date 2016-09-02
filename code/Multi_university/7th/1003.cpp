#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<cstring>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=2010;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;


int cnt;
int V[maxn];
char G[maxn][maxn];
int c[maxn],topo1[maxn],topo2[maxn];
bool T1[maxn];
vector<int> TT1,TT2;

bool dfs(int u,vector<int> &TT,int topo[]){
    c[u]=-1;
    for(int i=0;i<TT.size();++i){
        int v=TT[i];
        if(G[u][v]=='1'){
            if(c[v]<0) return false;
            else if(!c[v]&&!dfs(v,TT,topo)) return false;
        }
    }
    c[u]=1;topo[--cnt]=u;
    return true;
}

bool toposort(vector<int> &TT,int topo[]){
    cnt=TT.size();
    memset(c,0,sizeof(c));
    for(int i=0;i<TT.size();++i){
        int u=TT[i];
        if(!c[u]&&!dfs(u,TT,topo)) return false;
    }
    return true;
}

int find(int u,int m){
    for(int i=0;i<m;++i){
        if(G[u][topo1[i]]=='1'){
            for(int j=i+1;j<m;++j)
                if(G[u][topo1[j]]=='0')
                    return -1;
            return i;
        }
    }
    return m;
}

int length(int n){
    int leng=1;
    for(int i=1;i<n;++i){
        if(V[i]>=V[leng-1])
            V[leng++]=V[i];
        else{
            int idx=upper_bound(V,V+leng,V[i])-V;
            if(idx==leng) continue;
            else V[idx]=V[i];
        }
    }
    return leng;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,n,m,k,icase=0;
    while(scanf("%d%d\n",&n,&m)){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;++i){
            gets(G[i]+1);
            for(int j=1;j<=n;++j)
                G[i][j]=G[i][j*2-1];
            G[i][n+1]=0;
        }

        memset(T1,false,sizeof(T1));
        for(int i=0;i<m;++i){
            scanf("%d",&u);
            T1[u]=true;
        }
        TT1.clear();TT2.clear();
        for(int i=1;i<=n;++i){
            if(T1[i]) TT1.push_back(i);
            else TT2.push_back(i);
        }
        if(toposort(TT1,topo1)&&toposort(TT2,topo2)){
//            cout<<topo1[0]<<" "<<topo1[1]<<endl;
            int cc=0;
            for(int i=0;i<n-m;++i){
                int k=find(topo2[i],m);
                if(k!=-1) V[cc++]=k;
            }
            printf("YES %d\n",cc?length(cc):0);
        }
        else printf("NO\n");
    }
    return 0;
}
