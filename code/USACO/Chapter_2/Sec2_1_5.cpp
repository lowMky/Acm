/*
ID: onlyazh1
LANG: C++
TASK: hamming
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
int n,b,d;
vector<int> ans;

int Cal(int a,int b){
    int res=0;
    while(a||b){
        if(a%2!=b%2)
            res++;
        a/=2;b/=2;
    }
    return res;
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("hamming.in");
    ofstream cout("hamming.out");
#endif
    cin>>n>>b>>d;
    for(int i=0;i<=(1<<b)-1;i++){
        bool flag=true;
        for(int j=0,sz=ans.size();j<sz;j++)
            if(Cal(i,ans[j])<d){
                flag=false;break;
            }
        if(flag) ans.push_back(i);
        if(ans.size()==n)
            break;
    }
    for(int i=0,sz=ans.size();;i++){
        cout<<ans[i];
        if(i==sz-1) break;
        if(i%10==9) cout<<endl;
        else cout<<" ";
    }
    cout<<endl;
    return 0;
}
