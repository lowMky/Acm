#include<bits/stdc++.h>

using namespace std;

int par[200100];
bool vis[200100];
set<int> S;
int ans;

bool dfs(int x,int &root){
    if(S.find(x)!=S.end()){
        if(root==-1){
            root=x;ans++;par[x]=x;
        }
        else if(x!=root){
            par[x]=root;ans++;
        }
    }
    if(vis[x]) return true;
    S.insert(x);
    vis[x]=true;
    return dfs(par[x],root);
}
int main(){
//    ifstream cin("in.txt");


    int n;cin>>n;
    for(int i=1;i<=n;++i)
        cin>>par[i];
    int root=-1;
    for(int i=1;i<=n;++i)
        if(par[i]==i){
            if(root==-1)
                root=i;
            else{
                ans++;par[i]=root;
            }
        }
//    for(int i=1;i<=n;++i)
//        cout<<par[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=n;++i){
        if(!vis[i]&&i!=root){
            S.clear();
            dfs(i,root);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;++i)
        cout<<par[i]<<" ";
    cout<<endl;
    return 0;
}
