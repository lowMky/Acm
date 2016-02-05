/*
ID: onlyazh1
LANG: C++
TASK: Graph and String
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int G[5010][5010];
int belong[5010];
int T;

int main(){
    int n,m,u,v,a,b;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u][v]=G[v][u]=true;
    }
    if(m==(n-1)*n/2){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
            cout<<'a';
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!G[i][j]){
                a=i;b=j;
            }
        }
    belong[a]=1;belong[b]=3;
    bool flag=true;
    for(int i=1;i<=n;i++)
        if(!belong[i]){
            if(G[a][i]&&G[b][i])
                belong[i]=2;
            else if(G[a][i])
                belong[i]=1;
            else if(G[b][i])
                belong[i]=3;
        }
    for(int i=1;i<=n;i++)
        if(!belong[i]){
            flag=false;
            break;
        }
    for(int i=1;i<=n&&flag;i++)
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(((abs(belong[j]-belong[i])<2)&&!G[i][j])||(abs(belong[j]-belong[i])==2&&G[i][j])){
                flag=false;break;
            }
        }
    if(flag){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
            cout<<char('a'+belong[i]-1);
    }
    else
        cout<<"No";
    cout<<endl;
    return 0;
}
