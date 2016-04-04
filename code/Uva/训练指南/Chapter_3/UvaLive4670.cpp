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
const int sig_size=26;
const int maxnode=20010;
char s[200][100];
char text[1000100];

map<string,int> M;
struct Ac{
    int ch[maxnode][sig_size];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    int cnt[maxnode];
    int sz;
    void init(){
        sz=1;memset(ch[0],0,sizeof(ch[0]));
        memset(cnt,0,sizeof(cnt));
        M.clear();
    }

    int idx(char ch){ return ch-'a'; }

    void insert(char *s,int v){
        int u=0;int n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
        M[string(s)]=v;
    }

    void get_fail(){
        queue<int> Que;
        f[0]=0;
        for(int c=0;c<sig_size;c++){
            int u=ch[0][c];
            if(u){
                Que.push(u);
                f[u]=0;last[u]=0;
            }
        }

        while(!Que.empty()){
            int r=Que.front();Que.pop();
            for(int c=0;c<sig_size;c++){
                int u=ch[r][c];
                if(!u){
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                Que.push(u);
                int v=f[r];
                while(v&&!ch[v][c]) v=f[v];
                f[u]=ch[v][c];
                last[u]= val[f[u]]?f[u]:last[f[u]];
            }
        }
    }

    void add(int j){
        if(j){
            cnt[val[j]]++;
            add(last[j]);
        }
    }

    void find(char *s){
        int n=strlen(s);int j=0;
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            j=ch[j][c];
            if(val[j]) add(j);
            else if(last[j]) add(last[j]);
        }
    }

}ac;

int main(){
    //ifstream cin("in.txt");
    int n;
    while(cin>>n&&n){
        ac.init();
        for(int i=1;i<=n;i++){
            cin>>s[i];
            ac.insert(s[i],i);
            M[s[i]]=i;
        }
        cin>>text;
        ac.get_fail();
        ac.find(text);
        int maxn=0;
        for(int i=1;i<=n;i++)
            maxn=max(maxn,ac.cnt[i]);
        cout<<maxn<<endl;
        for(int i=1;i<=n;i++)
            if(ac.cnt[M[s[i]]]==maxn)
                cout<<s[i]<<endl;

    }
    return 0;
}
