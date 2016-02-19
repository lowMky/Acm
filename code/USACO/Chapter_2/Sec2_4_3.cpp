/*
ID: onlyazh1
LANG: C++
TASK: cowtour
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
struct Node{
    int x,y;
}p[200];
int n;
double G[200][200];
double dist[200];

double Cal(Node a,Node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void Floyd(){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(G[i][j]!=1e9)
                dist[i]=max(dist[i],G[i][j]);
}
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("cowtour.in");
    ofstream cout("cowtour.out");
#endif

    cin>>n;
    for(int i=0;i<n;i++)
        dist[i]=0;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            char t;cin>>t;
            if(i==j) continue;
            if(t=='1') G[i][j]=Cal(p[i],p[j]);
            else G[i][j]=1e9;
        }
    Floyd();
    double ans=1e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(G[i][j]!=1e9) continue;
            ans=min(ans,dist[i]+dist[j]+Cal(p[i],p[j]));
        }
    for(int i=0;i<n;i++)
        ans=max(ans,dist[i]);
     cout<<setprecision(6)<<setiosflags(ios::fixed)<<ans<<endl;
    return 0;
}
