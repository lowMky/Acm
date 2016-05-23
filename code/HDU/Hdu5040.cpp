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
const int inf=1e9+7;

struct Node{
    int x,y,st;
    Node(){};
    Node(int _x,int _y,int _st){
        x=_x;y=_y;st=_st;
    }
    bool operator < (const Node &A) const{
        return st>A.st;
    }
};
char G[510][510];
bool tag[510][510][4];
int dp[510][510][4];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

priority_queue<Node> Que;
int n;
Node S,E;
char dir[]="NESW";
void Tag(int x,int y,char ch){
    int d;
    for(d=0;d<4;d++)
        if(dir[d]==ch)
            break;
    int tx,ty;
    for(int i=0;i<4;i++){
        tag[y][x][i]=true;
        tx=x+dx[(i+d)%4];
        ty=y+dy[(i+d)%4];
        if(0<=tx&&tx<n&&0<=ty&&ty<n)
            tag[ty][tx][i]=true;
    }
}

int main(){
    //freopen("in.txt","r",stdin);

    int T,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                for(int k=0;k<4;++k){
                    tag[i][j][k]=false;
                    dp[i][j][k]=inf;
                }

        for(int i=0;i<n;++i){
            scanf("%s",G[i]);
            for(int j=0;j<n;++j){
                if(G[i][j]=='M')
                    S=Node(j,i,0);
                else if(G[i][j]=='T')
                    E=Node(j,i,0);
                else if(isalpha(G[i][j]))
                    Tag(j,i,G[i][j]);
            }
        }
        printf("Case #%d: ",++icase);
        while(!Que.empty())
            Que.pop();
        Que.push(S);
        dp[S.y][S.x][0]=0;
        Node now,to;
        int nowt,tot;
        bool flag=false;
        while(!Que.empty()){
            now=Que.top();Que.pop();
            //cout<<now.y<<" "<<now.x<<" "<<now.st%4<<" "<<now.st<<endl;
            if(now.x==E.x&&now.y==E.y){
                printf("%d\n",now.st);
                flag=true;break;
            }
            if(now.st>dp[now.y][now.x][now.st%4])
                continue;
            nowt=now.st%4;
            tot=(now.st+1)%4;
            if(now.st+1<dp[now.y][now.x][tot]){
                dp[now.y][now.x][(now.st+1)%4]=now.st+1;
                Que.push(Node(now.x,now.y,now.st+1));
            }
            for(int i=0;i<4;i++){
                to.x=now.x+dx[i];
                to.y=now.y+dy[i];
                if(0>to.x||to.x>=n||0>to.y||to.y>=n||G[to.y][to.x]=='#')
                    continue;

                to.st=now.st+((tag[now.y][now.x][nowt]||tag[to.y][to.x][nowt])?3:1);
                if(to.st<dp[to.y][to.x][to.st%4]){
                    dp[to.y][to.x][to.st%4]=to.st;
                    Que.push(to);
                }
            }
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}
