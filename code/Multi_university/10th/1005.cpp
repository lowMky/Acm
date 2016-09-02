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

const int maxn=200100;
const int maxm=2000010;
const int inf=1e9+7;


int val[maxn];
int ans[maxn];
set<int> S;
set<int>::iterator it;
vector<int> tag[2][maxn];

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,n,m,icase=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<n;++i){
            scanf("%d",&val[i]);
            tag[0][i].clear();
            tag[1][i].clear();
        }
        for(int i=1;i<=m;++i){
            scanf("%d%d",&u,&v);
            ans[i]=0;
            if(u>v) swap(u,v);
            tag[0][u].push_back(i);
            tag[1][v-1].push_back(i);
        }
        S.clear();
        for(int i=1;i<n;++i){
            for(int j=0;j<tag[0][i].size();++j)
                S.insert(tag[0][i][j]);
            if(!S.empty()){
                it=S.begin();
                ans[*it]+=val[i];
                it=S.end();it--;
                ans[(*it)+1]-=val[i];
            }
            for(int j=0;j<tag[1][i].size();++j)
                S.erase(tag[1][i][j]);
        }
        int sum=0;
        for(int i=1;i<=m;++i){
            sum+=ans[i];
            printf("%d\n",sum);
        }
    }
    return 0;
}
