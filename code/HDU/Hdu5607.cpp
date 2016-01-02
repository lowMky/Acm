#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const ll MOD=1e9+7;
const int MAXN=60; //¾ØÕó½×Êý
bool G[60][60];
int tot[60];
struct Matrix{
    ll m[MAXN][MAXN];
    Matrix()
    {
        memset(m,0,sizeof(m));
        for(int i=0;i<MAXN;i++)
            m[i][i]=1;
    }
    void clear(){
        memset(m,0,sizeof(m));
    }
    void show(){
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++)
                cout<<m[i][j]<<" ";
            cout<<endl;
        }
    }
};

Matrix mtMul(Matrix A,Matrix B)
{
    int i,j,k,tmp;
    Matrix C;
    C.clear();
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            for(int k=0;k<MAXN;k++)
                C.m[i][j]=(C.m[i][j]%MOD+(A.m[i][k]%MOD)*(B.m[k][j]%MOD))%MOD;
    return C;
}
Matrix mtPow(Matrix A,int k)
{
    k--;
    Matrix ans=A;
    while(k){
        if(k&1) ans=mtMul(ans,A);
        A=mtMul(A,A);
        k>>=1;
    }
    return ans;
}

ll Quick_pow(ll x,int m){
    ll sum=1;
    while(m){
        if(m&1) sum=((sum%MOD)*(x%MOD))%MOD;
        x=((x%MOD)*(x%MOD))%MOD;
        m>>=1;
    }
    return sum;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin>>n>>m){
        int u,v;
        Matrix M;
        M.clear();
        memset(G,0,sizeof(G));
        memset(tot,0,sizeof(tot));
        while(m--){
            cin>>u>>v;
            tot[u-1]++;
            G[v-1][u-1]=true;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(G[i][j]){
                    M.m[i][j]=((M.m[i][j])%MOD+Quick_pow(tot[j],1e9+5)%MOD)%MOD;
                }
        int Q;
        cin>>Q;

        while(Q--){
            int u,k;
            cin>>u>>k;
            Matrix ans=mtPow(M,k);
            //ans.show();
            for(int i=0;i<n;i++)
                cout<<ans.m[i][u-1]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
