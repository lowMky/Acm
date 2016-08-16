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


const double eps=1e-8;
const int maxn=210;
const int maxm=200010;
const int inf=1e9;
const ll MOD=772002;


char G[8][8];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,-1,0,-1,1,1,-1,0};

int n,m,mxn,cnt;
ll ans;
ll dp[26][520];
ll cc[520];

struct Node{
    int x,y;
    Node(){}
    Node(int _x,int _y){
        x=_x;y=_y;
    }
}node[12];

bool ok(int x,int y){
    if(x<0||x>=n) return false;
    if(y<0||y>=m) return false;
    return true;
}

bool nox(int x,int y){
    int tx,ty;
    for(int i=0;i<8;++i){
        tx=x+dx[i];
        ty=y+dy[i];
        if(ok(tx,ty)&&G[tx][ty]=='X')
            return false;
    }
    return true;
}

bool tt[8][8];

void col(int idx){
    int x=node[idx].x;
    int y=node[idx].y;
    int tx,ty;
    for(int i=0;i<8;++i){
        tx=x+dx[i];
        ty=y+dy[i];
        if(ok(tx,ty))
            tt[tx][ty]=true;
    }
}

int cal(){
    int cnt=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(G[i][j]=='X')
                node[cnt++]=Node(i,j);

    memset(dp,0,sizeof(dp));
    memset(cc,0,sizeof(cc));

    for(int i=0;i<(1<<cnt);++i){
        memset(tt,false,sizeof(tt));
        for(int k=0;k<cnt;++k){
            if(!((1<<k)&i)) col(k);
            tt[node[k].x][node[k].y]=true;
        }
        int tot=0;
        for(int p=0;p<n;++p)
            for(int q=0;q<m;++q)
                if(!tt[p][q]) tot++;
        cc[i]=tot;
    }
//    for(int i=0;i<(1<<cnt);++i)
//        cout<<cc[i]<<" ";
//    cout<<endl;
    dp[0][0]=1;
    for(int i=1;i<=mxn;++i){
        for(int j=0;j<(1<<cnt);++j){
            int dd=0;
            for(int k=0;k<cnt;++k){
                if((1<<k)&j){
                    ++dd;
                    dp[i][j]=(dp[i][j]+dp[i-1][j-(1<<k)])%MOD;
                }
            }
            dp[i][j]=(dp[i][j]+dp[i-1][j]*(cc[j]-(i-1)+dd))%MOD;
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    return dp[mxn][(1<<cnt)-1]%MOD;
}

void dfs(int now,int ccc){
    if(now==mxn){
        if(ccc%2==0)
            ans=(ans+cal())%MOD;
        else ans=(ans-cal()+MOD)%MOD;
        return ;
    }
    dfs(mxn,ccc);
    for(int nex=now+1;nex<mxn;++nex){
        int x=nex/m;int y=nex%m;
        if(ok(x,y)&&G[x][y]=='.'&&nox(x,y)){
            G[x][y]='X';
//            cout<<x<<" "<<y<<endl;
            dfs(nex,ccc+1);
            G[x][y]='.';
        }
    }
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,icase=0;
    while(scanf("%d%d",&n,&m)!=EOF){
//        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;++i)
            scanf("%s",G[i]);

        bool flag=true;
        for(int i=0;i<n&&flag;++i)
            for(int j=0;j<m;++j)
                if(G[i][j]=='X'&&!nox(i,j)){
                    flag=false;break;
                }


        if(!flag){
            printf("Case #%d: %d\n",++icase,0);
            continue;
        }

        ans=0;mxn=n*m;
        dfs(-1,0);
        printf("Case #%d: %lld\n",++icase,ans);
    }
    return 0;
}
