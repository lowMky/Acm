#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=100100;
const int inf=0x3f3f3f3f;
const ll MOD=1e9+7;

int n;
int len[1010][1010][8];
int G[1010][1010];
int cnt[1010][1010][8][4];
double lgg[4];

ll qpow(ll x,ll p){
    ll ret=1;
    while(p){
        if(p&1) ret=ret*x%MOD;
        x=x*x%MOD;
        p>>=1;
    }
    return ret;
}

void pre_make(){
    for(int i=1;i<=3;++i)
        lgg[i]=log10(i);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=3;++k){
                cnt[i][j][0][k]=cnt[i][j-1][0][k]+(G[i][j]==k);
                cnt[j][i][2][k]=cnt[j-1][i][2][k]+(G[j][i]==k);
            }
            if(G[i][j]==0) len[i][j][0]=0;
            else len[i][j][0]=len[i][j-1][0]+1;
            if(G[j][i]==0) len[j][i][2]=0;
            else len[j][i][2]=len[j-1][i][2]+1;
        }
    }
    for(int i=n;i>0;--i){
        for(int j=n;j>0;--j){
            for(int k=1;k<=3;++k){
                cnt[i][j][4][k]=cnt[i][j+1][4][k]+(G[i][j]==k);
                cnt[j][i][6][k]=cnt[j+1][i][6][k]+(G[j][i]==k);
            }
            if(G[i][j]==0) len[i][j][4]=0;
            else len[i][j][4]=len[i][j+1][4]+1;
            if(G[j][i]==0) len[j][i][6]=0;
            else len[j][i][6]=len[j+1][i][6]+1;
        }
    }

    int j;
    for(int z=1;z<n*2;++z){
        for(int i=max(1,n-z+1);i<=n;++i){
            j=z+i-n;
            for(int k=1;k<=3;++k){
                cnt[i][j][1][k]=cnt[i-1][j-1][1][k]+(G[i][j]==k);
                cnt[i][n-j+1][3][k]=cnt[i-1][n-j+2][3][k]+(G[i][n-j+1]==k);
            }
            if(G[i][j]==0) len[i][j][1]=0;
            else len[i][j][1]=len[i-1][j-1][1]+1;
            if(G[i][n-j+1]==0) len[i][n-j+1][3]=0;
            else len[i][n-j+1][3]=len[i-1][n-j+2][3]+1;
        }
    }

    for(int z=1;z<n*2;++z){
        for(int i=min(n,n*2-z);i>0;--i){
            j=z+i-n;
            for(int k=1;k<=3;++k){
                cnt[i][j][7][k]=cnt[i+1][j-1][7][k]+(G[i][j]==k);
                cnt[i][n-j+1][5][k]=cnt[i+1][n-j+2][5][k]+(G[i][n-j+1]==k);
            }
            if(G[i][j]==0) len[i][j][7]=0;
            else len[i][j][7]=len[i+1][j-1][7]+1;
            if(G[i][n-j+1]==0) len[i][n-j+1][5]=0;
            else len[i][n-j+1][5]=len[i+1][n-j+2][5]+1;
        }
    }
}


pair<double,ll> cal(int x,int y){
    int cc[4],minl;
    double retmp;
    pair<double,ll> ret;

    ret.first=0;ret.second=0;

    minl=inf;
    memset(cc,0,sizeof(cc));
    for(int i=0;i<8;i+=2)
        minl=min(minl,len[x][y][i]);
//    cout<<"minl="<<minl<<endl;
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][0][i]-cnt[x][y-minl][0][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][2][i]-cnt[x-minl][y][2][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][4][i]-cnt[x][y+minl][4][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][6][i]-cnt[x+minl][y][6][i]);
//    cout<<cc[3]<<endl;
    cc[G[x][y]]-=3;
    for(int i=1;i<=3;++i)
        ret.first+=cc[i]*lgg[i];
    ret.second=(qpow(2,cc[2])*qpow(3,cc[3]))%MOD;

    retmp=0;minl=inf;
    memset(cc,0,sizeof(cc));
    for(int i=1;i<8;i+=2)
        minl=min(minl,len[x][y][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][1][i]-cnt[x-minl][y-minl][1][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][3][i]-cnt[x-minl][y+minl][3][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][5][i]-cnt[x+minl][y+minl][5][i]);
    for(int i=1;i<=3;++i)
        cc[i]+=(cnt[x][y][7][i]-cnt[x+minl][y-minl][7][i]);
    cc[G[x][y]]-=3;
    for(int i=1;i<=3;++i)
        retmp+=cc[i]*lgg[i];
    if(retmp>ret.first){
        ret.first=retmp;
        ret.second=(qpow(2,cc[2])*qpow(3,cc[3]))%MOD;
    }
    return ret;
}

ll work(){
    ll ret=0;double rett=-1;
    pair<double,ll> tmp;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(!G[i][j])
                continue;
            tmp=cal(i,j);
            if(tmp.first>rett){
                rett=tmp.first;
                ret=tmp.second;
            }
        }
    }
    return ret;
}

char st[1010];
int main(){
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",st);
        for(int j=1;j<=n;++j)
            G[i][j]=st[j-1]-'0';
    }
    pre_make();
    printf("%I64d\n",work());
    return 0;
}
