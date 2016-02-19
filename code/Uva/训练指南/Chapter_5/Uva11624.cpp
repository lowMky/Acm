/*
ID: onlyazh1
LANG: C++
TASK: Fire!
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
char M[1010][1010];
bool vis[1010][1010];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
struct Node{
    int x,y,tag,dep;
    Node(){}
    Node(int _y,int _x,int _tag,int _dep){
        y=_y,x=_x,tag=_tag,dep=_dep;
    }
};
queue<Node> Que;
int main(){

    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        memset(vis,false,sizeof(vis));
        while(!Que.empty()) Que.pop();

        int n,m;cin>>n>>m;
        Node tmp,to;
        for(int i=0;i<n;i++){
            cin>>M[i];
            for(int j=0;j<m;j++){
                if(M[i][j]=='J'){
                    tmp=Node(i,j,1,0);
                    vis[i][j]=true;
                }
                if(M[i][j]=='F'){
                    Que.push(Node(i,j,0,0));
                    vis[i][j]=true;
                }
            }
        }
        bool flag=false;Que.push(tmp);
        while(!Que.empty()){
            tmp=Que.front();Que.pop();
            if(tmp.tag&&(tmp.x==0||tmp.x==m-1||tmp.y==0||tmp.y==n-1)){
                cout<<tmp.dep+1<<endl;flag=true;break;
            }
            for(int i=0;i<4;i++){
                to.x=tmp.x+dx[i];
                to.y=tmp.y+dy[i];
                to.dep=tmp.dep+1;
                to.tag=tmp.tag;
                if(to.x<0||to.x>=m||to.y<0||to.y>=n||vis[to.y][to.x]||M[to.y][to.x]!='.')
                    continue;
                else{
                    if(to.tag){
                        Que.push(to);
                        vis[to.y][to.x]=true;
                    }
                    else{
                        Que.push(to);
                        vis[to.y][to.x]=true;
                    }
                }
            }

        }
        if(!flag)
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
