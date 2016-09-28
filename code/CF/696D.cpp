#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=210;
const ll inf=1e18;
const ll MOD=1e9+7;
const int max_node=240;
const int sigma_size=26;

struct Mat{
    ll M[maxn][maxn];

    Mat(){
        for(int i=0;i<maxn;++i)
            for(int j=0;j<maxn;++j){
                if(i==j) M[i][j]=0;
                else M[i][j]=-inf;
            }
    }

    friend Mat operator * (Mat &A,Mat &B){
        Mat tmp;
        for(int i=0;i<maxn;++i)
            for(int j=0;j<maxn;++j){
                for(int k=0;k<maxn;++k){
                    tmp.M[i][j]=max(tmp.M[i][j],A.M[i][k]+B.M[k][j]);
                }
            }
        return tmp;
    }

    friend Mat operator ^(Mat &A,ll n){
        Mat ret;
        while(n){
            if(n&1) ret=ret*A;
            A=A*A;
            n>>=1;
        }
        return ret;
    }
}mat;

struct Trie{
    int ch[max_node][sigma_size];
    ll val[max_node];
    int fail[max_node];
//    int last[max_node];
    int sz;

    void clear(){
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }

    int idx(char c){
        return c-'a';
    }

    void insert(char *s,int w){
        int u=0,n=strlen(s);
        for(int i=0;i<n;++i){
            int id=idx(s[i]);
            if(!ch[u][id]){
                ch[u][id]=sz;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz++]=0;
            }
            u=ch[u][id];
        }
        val[u]+=w;
    }

    void getFail(){
        fail[0]=0;
        queue<int> q;
        for(int i=0;i<26;++i)
            if(ch[0][i]){
                fail[ch[0][i]]=0;
                q.push(ch[0][i]);
//                last[ch[0][i]]=0;
            }
        while(!q.empty()){
            int r=q.front();q.pop();
            val[r]+=val[fail[r]];
            for(int c=0;c<26;++c){
                int u=ch[r][c];
                if(!u){
                    ch[r][c]=ch[fail[r]][c];
                    continue;
                }
                q.push(u);
                int v=fail[r];
                while(v&&!ch[v][c]) v=fail[v];
                fail[u]=ch[v][c];
//                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
}ac;

int sval[maxn];
char stmp[240];

int main(){
//    ifstream cin("in.txt");
    Mat tmp;

    int n;ll maxL;
    cin>>n>>maxL;
    for(int i=0;i<n;++i)
        cin>>sval[i];

    ac.clear();
    for(int i=0;i<n;++i){
        cin>>stmp;
        ac.insert(stmp,sval[i]);
    }
    ac.getFail();

    for(int i=0;i<ac.sz;++i)
        for(int j=0;j<ac.sz;++j)
            mat.M[i][j]=-inf;

    for(int i=0;i<ac.sz;++i)
        for(int j=0;j<26;++j){
            int c=ac.ch[i][j];
            mat.M[i][c]=ac.val[c];
        }

//    for(int i=0;i<ac.sz;++i,cout<<endl)
//        for(int j=0;j<ac.sz;++j)
//            cout<<mat.M[i][j]<<" ";
//    cout<<endl<<endl;

    mat=mat^maxL;
//    for(int i=1;i<ac.sz;++i,cout<<endl)
//        for(int j=1;j<ac.sz;++j)
//            cout<<mat.M[i][j]<<" ";
//    cout<<endl<<endl;
    ll ans=0;
    for(int i=0;i<ac.sz;++i)
            ans=max(ans,mat.M[0][i]);
    cout<<ans<<endl;

    return 0;
}


