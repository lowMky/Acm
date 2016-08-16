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

const int maxn=100100;
const int maxm=200010;
const int inf=1e9;

int val[maxn];
int dp1[maxn]; //下回
int dp2[maxn]; //下不回
int dp3[maxn]; //上回
int dp4[maxn]; //上不回
int ans[maxn];
pair<int,int> p[maxn][2];

struct Edge{
    int v,w;
    Edge(int _v,int _w){
        v=_v;w=_w;
    }
};

vector<Edge> G[maxn];

void dfs1(int u,int fa){
    int v,w;
    vector<pair<int,int> > ptmp;
    ptmp.clear();
    dp1[u]=dp2[u]=val[u];
    for(int i=0;i<G[u].size();++i){
        v=G[u][i].v;w=G[u][i].w;
        if(v==fa) continue;
        dfs1(v,u);
        if(dp1[v]-w*2>0)
            dp1[u]+=max(0,dp1[v]-w*2);

        if(dp2[v]-w>0){
            if(dp1[v]-w*2>0)
                ptmp.push_back(make_pair(dp1[v]-dp2[v]-w,v));
            else ptmp.push_back(make_pair(w-dp2[v],v));
        }
//        cout<<"v="<<v<<" "<<"w="<<w<<" "<<dp1[v]<<" "<<dp1[u]<<endl;
    }
//    cout<<"u="<<u<<endl;
//    for(int i=0;i<ptmp.size();++i){
//        printf("%d %d\n",ptmp[i].second,ptmp[i].first);
//    }
//    cout<<endl;

    if(ptmp.size()==0){
        p[u][0].first=p[u][1].first=0;
        p[u][0].second=p[u][1].second=-1;
        return ;
    }
    sort(ptmp.begin(),ptmp.end());

    p[u][0]=ptmp[0];

//    cout<<"u="<<u<<endl;
//    cout<<p[u][0].second<<" "<<p[u][0].first<<endl;
    if(ptmp.size()>1)
        p[u][1]=ptmp[1];
    else{
        p[u][1].first=0;
        p[u][1].second=-1;
    }

//    cout<<dp1[u]<<" "<<p[u][0].first<<endl;
    dp2[u]=max(dp2[u],dp1[u]-p[u][0].first);
//    cout<<"v="<<v<<" "<<dp2[v]<<" "<<"u="<<u<<" "<<dp2[u]<<endl;
}

void dfs2(int u,int fa){
    int v,w,tmp;
    for(int i=0;i<G[u].size();++i){
        v=G[u][i].v;w=G[u][i].w;
        if(v==fa) continue;
        dp3[v]=dp4[v]=val[v];

        tmp=0;
        tmp+=(dp3[u]+dp1[u]-val[u]);
        tmp-=max(0,dp1[v]-w*2);
        dp3[v]=max(0,tmp-w*2)+val[v];
//        cout<<"v="<<v<<" dp3[v]="<<dp3[v]<<endl;

//        cout<<"v="<<v<<endl;
        tmp=0;
        tmp+=(dp4[u]+dp1[u]-val[u]);
        tmp-=max(0,dp1[v]-w*2);
        dp4[v]=max(0,tmp-w)+val[v];
//        cout<<"v="<<v<<" dp4[v]="<<dp4[v]<<endl;

        tmp=0;
        tmp+=(dp3[u]+dp1[u]-val[u]);
        tmp-=max(0,dp1[v]-w*2);
//        cout<<"v="<<v<<" "<<"tmp="<<tmp<<endl;
        if(v==p[u][0].second){
            tmp-=p[u][1].first;
//            cout<<"1"<<" "<<tmp<<" "<<p[u][1].first<<endl;
        }
        else{
            tmp-=p[u][0].first;
//            cout<<"2"<<" "<<tmp<<" "<<p[u][0].first<<endl;
        }
        dp4[v]=max(dp4[v],max(0,tmp-w)+val[v]);
        dfs2(v,u);
    }
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);
    int T,n,m,u,v,w,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<=n;++i){
            G[i].clear();
            dp1[i]=dp2[i]=dp3[i]=dp4[i]=ans[i]=0;
        }

        for(int i=1;i<=n;++i)
            scanf("%d",&val[i]);
        for(int i=0;i<n-1;++i){
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(Edge(v,w));
            G[v].push_back(Edge(u,w));
        }
        dfs1(1,1);
//        for(int i=1;i<=n;++i)
//            printf("%d ",dp1[i]);
//        printf("\n");
//        for(int i=1;i<=n;++i)
//            printf("%d ",dp2[i]);
//        printf("\n");

        dp3[1]=dp4[1]=val[1];
        dfs2(1,1);
//        for(int i=1;i<=n;++i)
//            printf("%d ",dp3[i]);
//        printf("\n");
//        for(int i=1;i<=n;++i)
//            printf("%d ",dp4[i]);
//        printf("\n");

        for(int i=1;i<=n;++i){
            ans[i]=max(ans[i],dp1[i]+dp4[i]-val[i]);
            ans[i]=max(ans[i],dp2[i]+dp3[i]-val[i]);
        }
        printf("Case #%d:\n",++icase);
        for(int i=1;i<=n;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
