/*
ID: onlyazh1
LANG: C++
TASK: maze1
*/
#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;

struct Node{
    int x,y;
};

string M[220];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int dist[220][110];
bool vis[220][110];
Node A,B;int w,h;

void BFS(Node &A){
    Node tmp,to;
    memset(vis,false,sizeof(vis));
    queue<Node> Que;
    Que.push(A);
    vis[A.y][A.x]=true;
    dist[A.y][A.x]=0;
    while(!Que.empty()){
        tmp=Que.front();Que.pop();
        for(int i=0;i<4;i++){
            to.x=tmp.x+dx[i];
            to.y=tmp.y+dy[i];
            if(to.x<0||to.x>2*w||to.y<0||to.y>2*h||vis[to.y][to.x]||M[to.y][to.x]!=' ')
                continue;
            else{
                Que.push(to);
                vis[to.y][to.x]=true;
                if(dist[to.y][to.x]) dist[to.y][to.x]=min(dist[to.y][to.x],dist[tmp.y][tmp.x]+1);
                else dist[to.y][to.x]=dist[tmp.y][tmp.x]+1;
            }
        }
    }
}
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("maze1.in");
    ofstream cout("maze1.out");
#endif

    cin>>w>>h;getline(cin,M[0]);
    for(int i=0;i<=2*h;i++){
        getline(cin,M[i]);
        for(int j=0;j<=2*w;j++){
            if((i==0||i==2*h||j==0||j==2*w)&&M[i][j]==' '){
                if(A.x||A.y) B.x=j,B.y=i;
                else A.x=j,A.y=i;
            }
        }
    }
    BFS(A);BFS(B);
    int ans=0;
    for(int i=0;i<=2*h;i++)
        for(int j=0;j<=2*w;j++)
            ans=max(ans,dist[i][j]);
    cout<<(ans+1)/2<<endl;

    return 0;
}
