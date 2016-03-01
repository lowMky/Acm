/*
ID: onlyazh1
LANG: C++
TASK: Warfare And Logistics
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

const int maxn=60;
const int maxm=1000010;
const int INF=0x3f3f3f3f;
int n,m,u,v,w;
int G[maxn][maxn];
ll dist[maxn];
int pre[maxn];
string anss;
char tmp[200];
int cc=0;
char s,e;
struct Node{
    int u;ll w;
    Node(){};
    Node(int _u,ll _w){
        u=_u;w=_w;
    }
    bool operator < (const Node &A) const{
        return w>A.w;
    }
};
int cha(char x){return x>='a'?x-'a'+26:x-'A';}

char cha(int x){return x<26?x+'A':x-26+'a';}
/*
void Dijkstra(ll mid){
    memset(dist,0,sizeof(dist));
    priority_queue<Node> Que;
    dist[cha(s)]=mid;
    Que.push(Node(cha(s),mid));
    while(!Que.empty()){
        Node u=Que.top();Que.pop();
        for(int i=0;i<60;i++){
            if(!G[u.u][i]) continue;
            if(G[u.u][i]==1){
                if(dist[i]<u.w-(u.w+19)/20){
                    pre[i]=u.u;
                    dist[i]=u.w-(u.w+19)/20;
                    Que.push(Node(i,dist[i]));
                }
            }
            else{
                if(dist[i]<u.w-1){
                    pre[i]=u.u;
                    dist[i]=u.w-1;
                    Que.push(Node(i,dist[i]));
                }
            }
        }
    }
}
*/

void Dijkstra(ll d){
    for(int i=0;i<60;i++) dist[i]=(1LL<<60);
    priority_queue<Node> Que;
    dist[cha(e)]=d;
    Que.push(Node(cha(e),d));
    while(!Que.empty()){
        Node u=Que.top();Que.pop();
        for(int i=0;i<60;i++){
            if(!G[u.u][i]) continue;
            if(G[u.u][i]==1){
                int w=(u.w%19==0?u.w/19:u.w/19+1);
                if(dist[i]>u.w+w){
                    pre[i]=u.u;
                    dist[i]=u.w+w;
                    Que.push(Node(i,dist[i]));
                }
                else if(dist[i]==u.w+w)
                    pre[i]=min(pre[i],u.u);
            }
            else{
                if(dist[i]>u.w+1){
                    pre[i]=u.u;
                    dist[i]=u.w+1;
                    Que.push(Node(i,dist[i]));
                }
                else if(dist[i]==u.w+1)
                    pre[i]=min(pre[i],u.u);
            }
        }
    }
}
/*
void dfs(int u){
    if(cha(u)!=s){
        dfs(pre[u]);
        tmp[cc++]='-';
    }
    tmp[cc++]=cha(u);
    tmp[cc]='\0';
}
*/
int main(){
    //ifstream cin("in.txt");
    int icase=0;
    while(cin>>m&&m!=-1){
        memset(G,0,sizeof(G));
        char x,y;ll p;
        /*
        while(m--){
            cin>>x>>y;
            u=cha(x);v=cha(y);
            G[u][v]=(y<'a'?1:2);
            G[v][u]=(x<'a'?1:2);
        }
        cin>>p>>s>>e;
        ll L=0,R=(1LL<<60);
        while(L<R){
            ll mid=L+(R-L)/2;
            Dijkstra(mid);
            if(dist[cha(e)]>=p){
                R=mid;cc=0;
                dfs(cha(e));
                anss=string(tmp);
            }
            else L=mid+1;
        }
        */

        while(m--){
            cin>>x>>y;
            u=cha(x);v=cha(y);
            G[u][v]=(x<'a'?1:2);
            G[v][u]=(y<'a'?1:2);
        }
        cin>>p>>s>>e;
        Dijkstra(p);
        cout<<"Case "<<++icase<<":"<<endl;
        cout<<dist[cha(s)]<<endl;
        int v=cha(s);
        while(v!=cha(e)){
            cout<<cha(v)<<"-";
            v=pre[v];
        }
        cout<<e<<endl;
    }
    return 0;
}


