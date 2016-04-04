/*
ID: onlyazh1
LANG: C++
TASK: Remember the Word
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<algorithm>

using namespace std;
typedef long long ll;
const int maxnode=4001000;
const int sigma_size=62;

struct Trie{
    int sz;
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode];
    int end[maxnode];

    //Trie() {sz=1;memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c){
        if('a'<=c&&c<='z') return c-'a';
        if('A'<=c&&c<='Z') return c-'A'+26;
        if('0'<=c&&c<='9') return c-'0'+52;
    }
    void init(){
        sz=1;memset(ch[0],0,sizeof(ch[0]));
        cnt[0]=val[0]=end[0]=0;
    }
    ll insert(char *s){
        ll ret=0;
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=cnt[sz]=end[sz]=0;ch[u][c]=sz++;
            }
            ret+=cnt[u];
            cnt[u]++;
            u=ch[u][c];
            ret+=val[u];
            ret+=end[u];
            val[u]++;
        }
        ret+=end[u];
        ret+=cnt[u];
        end[u]++;
        return ret;
    }
}Tr;
char tmp[1010];

int main(){
    //freopen("in.txt","r",stdin);
    int n,icase=0;
    while(scanf("%d",&n)&&n){
        ll ans=0;Tr.init();
        //for(int i=0;i<5;i++)
            //cout<<"***"<<Tr.val[i]<<" "<<Tr.cnt[i]<<" "<<Tr.end[i]<<endl;
        for(int i=0;i<n;i++){
            scanf("%s",tmp);
            ans+=Tr.insert(tmp);
        }
        printf("Case %d: %lld\n",++icase,ans);
    }
    return 0;
}
