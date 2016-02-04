/*
ID: onlyazh1
LANG: C++
TASK: holstein
*/

#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

//#define LOCAL
typedef long long ll;
vector<int> V;
int ans[20];
int n,p,minn;
int cont[20][30];
int ned[30];
int tmp[30];
bool Jud(){
    for(int i=0;i<n;i++)
        if(tmp[i]<ned[i])
            return false;
    return true;
}
void DFS(int idx){
    if(Jud()){
        if(minn>V.size()){
            minn=V.size();
            for(int i=0;i<minn;i++)
                ans[i]=V[i];
        }
        return ;
    }
    if(idx>=p||V.size()>=minn)
        return ;
    for(int i=0;i<n;i++)
        tmp[i]+=cont[idx][i];
    V.push_back(idx);
    DFS(idx+1);
    for(int i=0;i<n;i++)
        tmp[i]-=cont[idx][i];
    V.pop_back();
    DFS(idx+1);
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("holstein.in");
    ofstream cout("holstein.out");
#endif
    ans[10]=5;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ned[i];
    cin>>p;
    for(int i=0;i<p;i++)
        for(int j=0;j<n;j++)
            cin>>cont[i][j];
    minn=30;
    DFS(0);
    cout<<minn<<" ";
    for(int i=0;i<minn;i++){
        if(i) cout<<" ";
        cout<<ans[i]+1;
    }
    cout<<endl;
    return 0;
}
