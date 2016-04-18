/*
ID: onlyazh1
LANG: C++
TASK: test
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=100100;
typedef pair<int,bool> P;
vector<P> G[maxn];

vector<int> V[2];
vector<int> ans[2];
bool mov[maxn];
bool vis[maxn];
int n,m;
bool dfs(bool aim,int u,bool col){
    if(vis[u]){
        if(mov[u]!=col) return false;
        else return true;
    }

    mov[u]=col;
    vis[u]=true;
    if(col) V[1].push_back(u);
    else V[0].push_back(u);

    for(int i=0,sz=G[u].size();i<sz;i++){
        if(!dfs(aim,G[u][i].first,(G[u][i].second^col)!=aim))
            return false;
    }
    return true;
}

bool Jud(const bool col,vector<int> & ans){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            V[0].clear();V[1].clear();
            if(!dfs(col,i,0)){
                ans.clear();
                return false;
            }
            //cout<<V[0].size()<<"***"<<V[1].size()<<endl;
            if(V[0].size()<=V[1].size())
                for(int i=0,sz=V[0].size();i<sz;i++)
                    ans.push_back(V[0][i]);
            else for(int i=0,sz=V[1].size();i<sz;i++)
                    ans.push_back(V[1][i]);
        }
    }
    return true;
}

int main(){
    //ifstream cin("in.txt");
    char col;int u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>col;
        G[u].push_back(make_pair(v,col=='B'));
        G[v].push_back(make_pair(u,col=='B'));
    }
//    if(Jud(false,ans[0])){
//        cout<<"0"<<"  "<<ans[0].size()<<endl;
//        for(int i=0,sz=ans[0].size();i<sz;i++)
//            cout<<ans[0][i]<<" ";
//        cout<<endl;
//    }
//    if(Jud(true,ans[1])){
//        cout<<"0"<<"  "<<ans[1].size()<<endl;
//        for(int i=0,sz=ans[1].size();i<sz;i++)
//            cout<<ans[1][i]<<" ";
//        cout<<endl;
//    }
    if(Jud(false,ans[0])){
        if(Jud(true,ans[1])){
            if(ans[0].size()<ans[1].size()){
                cout<<ans[0].size()<<endl;
                for(int i=0,sz=ans[0].size();i<sz;i++)
                    cout<<ans[0][i]<<" ";
            }
            else{
                cout<<ans[1].size()<<endl;
                for(int i=0,sz=ans[1].size();i<sz;i++)
                    cout<<ans[1][i]<<" ";
            }
        }
        else{
            cout<<ans[0].size()<<endl;
            for(int i=0,sz=ans[0].size();i<sz;i++)
                cout<<ans[0][i]<<" ";
        }

    }
    else if(Jud(true,ans[1])){
        cout<<ans[1].size()<<endl;
        for(int i=0,sz=ans[1].size();i<sz;i++)
            cout<<ans[1][i]<<" ";
    }
    else cout<<-1<<endl;
    return 0;
}
