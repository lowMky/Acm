#include<time.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<math.h>
#include<cctype>
#define ll long long
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REPP(i,a,b,t) for(int (i)=(a);(i)<=(b);(i)+=(t))
#define rep(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define repp(i,a,b,t) for(int (i)=(a);(i)>=(b);(i)-=(t))
#define PII pair<int,int>
#define fst first
#define snd second
#define MP make_pair
#define PB push_back
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d%d",&(x),&(y))
#define RIII(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define DRI(x) int (x);scanf("%d",&(x))
#define DRII(x,y) int (x),(y);scanf("%d%d",&(x),&(y))
#define DRIII(x,y,z) int (x),(y),(z);scanf("%d%d%d",&(x),&(y),&(z))
#define RS(x) scanf("%s",x)
#define RSS(x,y) scanf("%s%s",x,y)
#define DRS(x) char x[maxn];scanf("%s",x)
#define DRSS(x,y) char x[maxn],y[maxn];scanf("%s%s",x,y)
#define MS0(a) memset((a),0,sizeof((a)))
#define MS1(a) memset((a),-1,sizeof((a)))
#define MS(a,b) memset((a),(b),sizeof((a)))
#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)(v).size()


using namespace std;

int T,n,m,w,flag;
double ans;
const int MAXN=1100;
const double inf=1e14;

struct v{
    int x,y;
}v[MAXN];

bool vis[MAXN];
double lowc[MAXN];
int pre[MAXN];
int po[MAXN];
double Max[MAXN][MAXN];//Max[i][j]表示在最小生成树中从i到j的路径中的最大边权
bool used[MAXN][MAXN];
double cost[MAXN][MAXN];
double a;

double dist(int i,int j)
{
    return sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y));
}
double Prim(double cost[][MAXN],int n)
{
    double ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    vis[0]=true;
    pre[0]=-1;
    for(int i=1;i<n;i++)
    {
        lowc[i]=cost[0][i];
        pre[i]=0;
    }
    lowc[0]=0;
    for(int i=1;i<n;i++)
    {
        double minc=inf;
        int p=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        if(p==-1)return -1;
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0;j<n;j++)
        {
            if(vis[j]&&j!=p)  Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        a=0;
        memset(v,0,sizeof(v));
        memset(po,0,sizeof(po));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)cost[i][j]=0;
                else cost[i][j]=inf;
            }
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&v[i].x,&v[i].y,&po[i]);
            for(int j=0;j<i;j++)
                cost[i][j]=cost[j][i]=dist(i,j);
        }

        ans=Prim(cost,n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j)
                {
                    if(!used[i][j])
                        a=max((po[i]+po[j])*1.0/(ans-Max[i][j]),a);
                    else
                        a=max((po[i]+po[j])*1.0/(ans-cost[i][j]),a);
                }
        printf("%.2f\n",a);
    }
    return 0;
}
