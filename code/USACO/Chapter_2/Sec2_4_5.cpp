/*
ID: onlyazh1
LANG: C++
TASK: fracdec
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
int vis[100010];
vector<int> ans;
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("fracdec.in");
    ofstream cout("fracdec.out");
#endif

    int a,b,cnt=1;
    int len=1;
    cin>>a>>b;
    cout<<a/b<<".";
    int t=a/b;
    if(t==0) len++;
    while(t){
        len++;t/=10;
    }
    a%=b;vis[a]=cnt++;a*=10;
    while(a){
        ans.push_back(a/b);
        if(vis[a%b]) break;
        a%=b;vis[a]=cnt++;
        a*=10;
    }
    if(ans.size()==0){
        cout<<"0"<<endl;
    }
    else{
        if(!a){
            for(int i=0,sz=ans.size();i<sz;i++){
                if(len%76==0) cout<<endl;
                cout<<ans[i];len++;
            }
            cout<<endl;
        }
        else{
            for(int i=0,sz=ans.size();i<sz;i++){
                if(len%76==0) cout<<endl;
                if(i==vis[a%b]-1){
                    cout<<"(";len++;
                }
                cout<<ans[i];len++;
            }
            cout<<")"<<endl;
        }
    }
    return 0;
}
