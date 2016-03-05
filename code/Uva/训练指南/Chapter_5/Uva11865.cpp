/*
ID: onlyazh1
LANG: C++
TASK: Low Cost Air Travel
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

const int maxn=100;
const int maxm=20000;
const int INF=0x3f3f3f3f;
int n,m,u,v,w,tot;
int in[maxn];
int id[maxn];
int pre[maxn];
int visit[maxn];
struct Edge{
    int u,v,c,b;
}edge[maxm],edge2[maxm];

bool zhuliu(int x,int root,int n,int m,Edge edge[]){
    int res=0,tn=0;
    while(1){
        for(int i=0;i<n;i++)
            in[i]=INF;
        for(int i=0;i<m;i++)
            if(edge[i].u!=edge[i].v&&edge[i].c<in[edge[i].v]&&edge[i].b>=x){
                pre[edge[i].v]=edge[i].u;
                in[edge[i].v]=edge[i].c;
            }
        for(int i=0;i<n;i++)
            if(i!=root&&in[i]==INF) return false;
        int tn=0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root]=0;
        for(int i=0;i<n;i++){
            res+=in[i];v=i;
            while(visit[v]!=i&&id[v]==-1&&v!=root){
                visit[v]=i;v=pre[v];
            }
            if(v!=root&&id[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u])
                    id[u]=tn;
                id[v]=tn++;
            }
        }
        if(tn==0) break;
        for(int i=0;i<n;i++)
            if(id[i]==-1) id[i]=tn++;
        for(int i=0;i<m;){
            v=edge[i].v;
            edge[i].u=id[edge[i].u];
            edge[i].v=id[edge[i].v];
            if(edge[i].u!=edge[i].v)
                edge[i++].c-=in[v];
            else
                swap(edge[i],edge[--m]);
        }
        n=tn;root=id[root];
    }
    return res<=tot;
}
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        int ub=0;
        cin>>n>>m>>tot;
        for(int i=0;i<m;i++){
            cin>>edge[i].u>>edge[i].v>>edge[i].b>>edge[i].c;
            edge2[i]=edge[i];
            ub=max(ub,edge[i].b);
        }
        if(!zhuliu(1,0,n,m,edge2)){
            cout<<"streaming not possible."<<endl;
            continue;
        }
        int L=1,R=ub;
        while(L<R){
            for(int i=0;i<m;i++)
                edge2[i]=edge[i];
            int mid=L+(R-L+1)/2;
            if(zhuliu(mid,0,n,m,edge2)) L=mid;
            else R=mid-1;
        }
        cout<<L<<" kbps"<<endl;
    }
    return 0;
}


