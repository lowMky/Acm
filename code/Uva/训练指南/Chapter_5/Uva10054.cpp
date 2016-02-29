/*
ID: onlyazh1
LANG: C++
TASK: The Necklace
*/
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
int deg[70];
int G[70][70];

void euler(int u){
    for(int i=1;i<=50;i++)
        if(G[u][i]){
            G[u][i]--;G[i][u]--;
            euler(i);
            cout<<i<<" "<<u<<endl;
        }
}

int main(){
    //ifstream cin("in.txt");
    int T,n,u,v,icase=0;
    cin>>T;
    while(T--){
        memset(deg,0,sizeof(deg));
        memset(G,0,sizeof(G));
        cin>>n;
        while(n--){
            cin>>u>>v;
            G[u][v]++;G[v][u]++;
            deg[u]++;deg[v]++;
        }

        if(icase) cout<<endl;
        cout<<"Case #"<<++icase<<endl;
        bool flag=true;
        for(int i=1;i<=50;i++)
            if(deg[i]%2==1){
                cout<<"some beads may be lost"<<endl;
                flag=false;break;
            }
        if(flag)
            euler(u);
    }
    return 0;
}
