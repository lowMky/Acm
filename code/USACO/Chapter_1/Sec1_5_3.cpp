/*
ID: onlyazh1
LANG: C++
TASK: sprime
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

int d[]={1,3,7,9};
int x[]={2,3,5,7};
vector<int> ans;
bool Jud(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
void DFS(int x,int n){
    if(n==0){
        ans.push_back(x);
        return ;
    }
    for(int i=0;i<4;i++)
        if(Jud(x*10+d[i]))
            DFS(x*10+d[i],n-1);
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("sprime.in");
    ofstream cout("sprime.out");
#endif
    int n;
    cin>>n;
    for(int i=0;i<4;i++)
        DFS(x[i],n-1);
    for(int i=0,sz=ans.size();i<sz;i++)
        cout<<ans[i]<<endl;
    return 0;
}
