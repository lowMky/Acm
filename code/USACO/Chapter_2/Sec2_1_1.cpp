/*
ID: onlyazh1
LANG: C++
TASK: castle
*/

#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

//#define LOCAL
typedef long long ll;
int G[60][60];
int belong[60][60];
bool vis[60][60];
int cnt[3000];
int idx,n,m;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void DFS(int y,int x){
    belong[y][x]=idx;
    cnt[idx]++;
    vis[y][x]=true;
    for(int i=0,t=1;i<4;i++,t*=2){
        int ty=y+dy[i];
        int tx=x+dx[i];
        if(!(t&G[y][x])&&!vis[ty][tx]&&0<=ty&&ty<n&&0<=tx&&tx<m)
            DFS(ty,tx);
    }
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("castle.in");
    ofstream cout("castle.out");
#endif
    cin>>m>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>G[i][j];
    int maxn=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                DFS(i,j);
                maxn=max(maxn,cnt[idx]);
                idx++;
            }
        }
    cout<<idx<<endl;
    cout<<maxn<<endl;
    maxn=0;
    int x,y;char dir;
    for(int j=0;j<m;j++)
        for(int i=n-1;i>=0;i--){
            if(i&&(2&G[i][j])&&belong[i][j]!=belong[i-1][j]&&cnt[belong[i][j]]+cnt[belong[i-1][j]]>maxn)
                    maxn=cnt[belong[i][j]]+cnt[belong[i-1][j]],y=i,x=j,dir='N';
            if(j<m-1&&(4&G[i][j])&&belong[i][j]!=belong[i][j+1]&&cnt[belong[i][j]]+cnt[belong[i][j+1]]>maxn)
                    maxn=cnt[belong[i][j]]+cnt[belong[i][j+1]],y=i,x=j,dir='E';
        }
    cout<<maxn<<endl;
    cout<<y+1<<" "<<x+1<<" "<<dir<<endl;
    return 0;
}
