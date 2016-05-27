/*
ID: onlyazh1
LANG: C++
TASK: test
*/


/*
ID: onlyazh1
LANG: C++
TASK: test
*/

#include<bits/stdc++.h>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long ll;

struct Node{
    int x,y,st,cnt;
    bool operator < (const Node & A) const{
        return st>A.st;
    }
};
char G[1010][1010];
bool vis[1010][1010][4];
priority_queue<Node> Que;
int can[1010][1010];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int main(){
    //freopen("in.txt","r",stdin);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%s",G[i]+1);
        for(int j=1;j<=m;++j){
            if(G[i][j]=='+') can[i][j]=15;
            if(G[i][j]=='-') can[i][j]=10;
            if(G[i][j]=='|') can[i][j]=5;
            if(G[i][j]=='^') can[i][j]=1;
            if(G[i][j]=='>') can[i][j]=2;
            if(G[i][j]=='<') can[i][j]=8;
            if(G[i][j]=='v') can[i][j]=4;
            if(G[i][j]=='L') can[i][j]=7;
            if(G[i][j]=='R') can[i][j]=13;
            if(G[i][j]=='U') can[i][j]=14;
            if(G[i][j]=='D') can[i][j]=11;
            if(G[i][j]=='*') can[i][j]=0;
        }
    }
    Node S,E,to,tmp;S.st=S.cnt=0;
    scanf("%d%d",&S.x,&S.y);
    scanf("%d%d",&E.x,&E.y);

    Que.push(S);
    //vis[S.x][S.y][0]=true;
    int dt,dn;
    bool flag=false;
    while(!Que.empty()){
        tmp=Que.top();Que.pop();

        if(tmp.x==E.x&&tmp.y==E.y){
            cout<<tmp.st<<endl;
            flag=true;break;
        }
//        cout<<tmp.x<<" "<<tmp.y<<endl;
        if(vis[tmp.x][tmp.y][tmp.cnt%4])
            continue;
        else vis[tmp.x][tmp.y][tmp.cnt%4]=true;

        for(int i=0;i<4;++i){
            to.x=tmp.x+dx[i];
            to.y=tmp.y+dy[i];
            if(to.x<=0||to.x>n||to.y<=0||to.y>m)
                continue;
            dn=(can[tmp.x][tmp.y]<<tmp.cnt)%16+(can[tmp.x][tmp.y]<<tmp.cnt)/16;
            dt=(can[to.x][to.y]<<tmp.cnt)%16+(can[to.x][to.y]<<tmp.cnt)/16;
//            cout<<dn<<" "<<dt<<endl;
            for(int k=0;k<4;++k){
                if(k){
                    dn=dn/8+(dn*2)%16;
                    dt=dt/8+(dt*2)%16;
//                    cout<<dn<<" "<<dt<<endl;
                }
                if(vis[to.x][to.y][(tmp.cnt+k)%4])
                    continue;
                if((dn&(1<<i))&&(dt&(1<<((i+2)%4)))){
                    //cout<<"True"<<endl;
                    to.st=tmp.st+k+1;
                    to.cnt=(tmp.cnt+k)%4;
                    Que.push(to);
                    break;
                }
            }
        }
    }

    if(!flag) cout<<-1<<endl;
    return 0;
}
