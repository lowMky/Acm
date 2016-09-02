#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<set>
using namespace std;

typedef long long ll;

const int maxm=1100100;
const int maxn=(1<<20)+12;

int sg[maxn];

int dfs(int x){
    if(sg[x]!=-1) return sg[x];
    int V[30],cnt=0;
    for(int i=0;i<20;++i){
        if(x&(1<<i)){
            for(int j=i-1;j>=0;--j){
                if((x&(1<<j))==0){
                    V[cnt++]=dfs(x-(1<<i)+(1<<j));
                    break;
                }
            }
        }
    }
    int now=0,cc=0;
    sort(V,V+cnt);
    cc=unique(V,V+cnt)-V;
//    for(int i=1;i<cnt;++i)
//        if(V[i]!=V[i-1])
//            V[++cc]=V[i];
    for(int i=0;i<cc;++i){
        if(V[i]==now) now++;
        else break;
    }
    return sg[x]=now;
}

void pre_process(){
    memset(sg,-1,sizeof(sg));
    for(int i=0;i<(1<<20);++i){
        if(sg[i]==-1) dfs(i);
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    ifstream cin("in.txt");
    pre_process();

    int T,ss,k,t,x;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        ss=0;
        while(n--){
            x=0;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&t);
                x=x+(1<<(20-t));
            }
            ss^=sg[x];
        }
        printf("%s\n",(ss==0?"NO":"YES"));
    }
    return 0;
}
