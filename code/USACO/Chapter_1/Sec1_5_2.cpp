/*
ID: onlyazh1
LANG: C++
TASK: pprime
*/

#include<set>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;

int p,q;
int num[20];
bool Jud(int tt){
    for(int i=2;i*i<=tt;i++)
        if(tt%i==0) return false;
    return true;
}

void DFS(int cnt,int n){
    if(cnt==(n+1) /2){
        for(int i=cnt;i<n;i++)
            num[i]=num[n-i-1];
        int tt=0;
        for(int i=0;i<n;i++)
            tt=tt*10+num[i];
        if(tt<p||tt>q) return;
        if(Jud(tt)) cout<<tt<<endl;
        return ;
    }
    for(int i=0;i<10;i++){
        num[cnt]=i;
        DFS(cnt+1,n);
    }
}

int main(){
    /*
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
#endif
    */
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);

    cin>>p>>q;
    int t1=p,t2=q,tt1=0,tt2=0;
    while(t1||t2){
        if(t1) tt1++;
        if(t2) tt2++;
        t1/=10,t2/=10;
    }
    for(int i=tt1;i<=tt2;i++){
        for(int j=1;j<=9;j++){
            num[0]=j;
            DFS(1,i);
        }
    }
    return 0;
}
