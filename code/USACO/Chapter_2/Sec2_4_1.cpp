/*
ID: onlyazh1
LANG: C++
TASK: ttwo
*/
#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;

struct Node{
    int x,y,dir;
};

char M[15][15];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
Node cow,peo;

bool Jud(){
    return cow.x==peo.x&&cow.y==peo.y;
}

void Walk(Node &A){
    int tx=A.x+dx[A.dir];
    int ty=A.y+dy[A.dir];
    if(tx<0||tx>9||ty<0||ty>9||M[ty][tx]=='*')
        A.dir=(A.dir+1)%4;
    else
        A.x=tx,A.y=ty;
}
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("ttwo.in");
    ofstream cout("ttwo.out");
#endif

    cow.dir=peo.dir=1;
    for(int i=0;i<10;i++){
        cin>>M[i];
        for(int j=0;j<10;j++){
            if(M[i][j]=='F')
                peo.x=j,peo.y=i;
            if(M[i][j]=='C')
                cow.x=j,cow.y=i;
        }
    }
    int ans=0;
    while(!Jud()){
        Walk(cow);
        Walk(peo);
        ans++;
        if(ans>200000){
            ans=0;break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
