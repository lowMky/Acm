/*
ID: onlyazh1
LANG: C++
TASK: 618D
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,u,v;
ll x,y;
vector<int> E[200100];
bool flag[200100];
ll ans;
void DFS(int u,int pre){
    int cnt=0;
    for(int i=0,sz=E[u].size();i<sz;i++){
        int v=E[u][i];
        if(v==pre) continue;
        DFS(v,u);
        if(flag[v]) cnt++;
    }
    if(cnt==0){
        flag[u]=true;
    }
    else if(cnt==1){
        ans+=x;
        flag[u]=true;
    }
    else if(cnt>=2){
        ans+=2*x;
        flag[u]=false;
    }
}
int main(){
    //ifstream cin("in.txt");
    cin>>n>>x>>y;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if(x>=y){
        bool tag=true;
        for(int i=1;i<=n;i++)
            if(E[i].size()==n-1)
                tag=false;
        if(tag) cout<<ll(y)*ll(n-1)<<endl;
        else cout<<ll(y)*ll(n-2)+ll(x)<<endl;
        return 0;
    }
    DFS(1,-1);
    cout<<ans+(n-ans/x-1)*y<<endl;
    return 0;
}
