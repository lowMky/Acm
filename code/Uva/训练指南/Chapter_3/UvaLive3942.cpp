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

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
typedef long long ll;
const int maxnode=400100;
const int sigma_size=26;
const int M=20071027;
int ch[maxnode][sigma_size];
bool val[maxnode];
struct Trie{
    int sz;
    Trie() {sz=1;memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c) {return c-'a';}

    void insert(char *s){
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=false;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=true;
    }
};

char s[300100];
char tmp[110];
int dp[300100];

int main(){
    ifstream cin("in.txt");
    int icase=0;
    while(cin>>s+1){
        int n;cin>>n;
        Trie Tr;
        for(int i=0;i<n;i++){
            cin>>tmp;Tr.insert(tmp);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;n=strlen(s+1);
        for(int i=1;i<=n;i++){
            for(int j=i,u=0;j<=n;j++){
                if(!ch[u][s[j]-'a'])
                    break;
                u=ch[u][s[j]-'a'];
                if(val[u])
                    dp[j]=(dp[j]%M+dp[i-1]%M)%M;
            }
        }
        cout<<"Case "<<++icase<<": "<<dp[n]%M<<endl;
    }
    return 0;
}
