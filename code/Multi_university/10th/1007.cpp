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

const int maxn=25;
const int maxm=2000010;
const int inf=1e9+7;
const ll MOD=1e9+7;

struct Matrix{
    ll M[maxn][maxn];
    Matrix(){
        memset(M,0,sizeof(M));
        for(int i=0;i<maxn;++i)
            M[i][i]=1;
    }
};

Matrix che(Matrix & A,Matrix &B){
    Matrix ret;
    memset(ret.M,0,sizeof(ret.M));
    for(int i=0;i<maxn;++i)
        for(int j=0;j<maxn;++j)
            for(int k=0;k<maxn;++k)
                ret.M[i][j]=(ret.M[i][j]+A.M[i][k]*B.M[k][j])%MOD;
    return ret;
}

Matrix pow(Matrix &A,ll n){
//    for(int i=0;i<maxn;++i,cout<<endl)
//        for(int j=0;j<maxn;++j)
//            cout<<A.M[i][j]<<" ";
//    cout<<endl;
    Matrix ret;
    while(n){
        if(n&1) ret=che(ret,A);
        A=che(A,A);
        n>>=1;
    }
    return ret;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    ll n;
    int T,u,v,m,k,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%d%d",&n,&m,&k);
        Matrix AA;memset(AA.M,0,sizeof(AA.M));
        for(int i=0;i<m;++i)
            AA.M[0][i]=k*(k-1);
        for(int i=1;i<=m;++i)
            AA.M[i][i-1]=k;
        for(int i=m;i<=m*2+1;++i)
            AA.M[m+1][i]=k*(k-1);
        for(int i=m+2;i<=m*2+1;++i)
            AA.M[i][i-1]=k;

//        for(int i=0;i<2*m+2;++i,cout<<endl)
//            for(int j=0;j<2*m+2;++j)
//                cout<<AA.M[i][j]<<" ";
//        cout<<endl;
        AA=pow(AA,n);
//        for(int i=0;i<2*m+2;++i,cout<<endl)
//            for(int j=0;j<2*m+2;++j)
//                cout<<AA.M[i][j]<<" ";
//        cout<<endl;
        ll ans=0;
        for(int i=m;i<=2*m+1;++i)
            ans=(ans+AA.M[i][0])%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
