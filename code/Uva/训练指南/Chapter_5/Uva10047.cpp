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
bool vis[30][30][4][5];
char M[30][30];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
struct Node{
    int x,y,tag,dep,col;
    Node(){}
    Node(int _y,int _x,int _tag,int _dep,int _col){
        y=_y,x=_x,tag=_tag,dep=_dep,col=_col;
    }
};
queue<Node> Que;
int main(){

    //ifstream cin("in.txt");
    int n,m,icase=0;
    while(cin>>n>>m&&(n||m)){
        if(icase) cout<<endl;
        cout<<"Case #"<<++icase<<endl;
        memset(vis,false,sizeof(vis));
        while(!Que.empty()) Que.pop();

        Node tmp,to,T;
        for(int i=0;i<n;i++){
            cin>>M[i];
            for(int j=0;j<m;j++)
                if(M[i][j]=='S'){
                    Que.push(Node(i,j,1,0,0));
                    vis[i][j][1][0]=true;
                }
        }
        bool flag=false;
        while(!Que.empty()){
            tmp=Que.front();Que.pop();
            if(M[tmp.y][tmp.x]=='T'&&tmp.col%5==0){
                cout<<"minimum time = "<<tmp.dep<<" sec"<<endl;flag=true;break;
            }
            to.x=tmp.x+dx[tmp.tag];
            to.y=tmp.y+dy[tmp.tag];
            to.col=tmp.col+1;
            to.dep=tmp.dep+1;
            to.tag=tmp.tag;
            if(to.x>=0&&to.x<m&&to.y>=0&&to.y<n&&!vis[to.y][to.x][to.tag][to.col%5]&&M[to.y][to.x]!='#'){
                Que.push(to);vis[to.y][to.x][to.tag][to.col%5]=true;
            }
            tmp.dep++;
            tmp.tag=(tmp.tag+1)%4;
            if(!vis[tmp.y][tmp.x][tmp.tag][tmp.col%5]){
                Que.push(tmp);
                vis[tmp.y][tmp.x][tmp.tag][tmp.col%5]=true;
            }
            tmp.tag=(tmp.tag+2)%4;
            if(!vis[tmp.y][tmp.x][tmp.tag][tmp.col%5]){
                Que.push(tmp);
                vis[tmp.y][tmp.x][tmp.tag][tmp.col%5]=true;
            }
        }
        if(!flag)
            cout<<"destination not reachable"<<endl;
    }
    return 0;
}
