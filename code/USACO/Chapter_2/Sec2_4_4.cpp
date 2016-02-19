/*
ID: onlyazh1
LANG: C++
TASK: comehome
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

//#define LOCAL
typedef unsigned long long ll;

int G[60][60];
void Floyd(){
    for(int k=0;k<52;k++)
        for(int i=0;i<52;i++)
            for(int j=0;j<52;j++)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("comehome.in");
    ofstream cout("comehome.out");
#endif

    int n;cin>>n;
    char a,b;int w;
    memset(G,0x3f3f3f3f,sizeof(G));
    while(n--){
        cin>>a>>b>>w;
        int u,v;
        u=a>='a'?a-'a'+26:a-'A';
        v=b>='a'?b-'a'+26:b-'A';
        G[u][v]=G[v][u]=min(G[u][v],w);
    }

    Floyd();
    int tag=0;
    for(int i=0;i<=24;i++)
        if(G[tag][25]>G[i][25])
            tag=i;
    cout<<char(tag+'A')<<" "<<G[tag][25]<<endl;
    return 0;
}
