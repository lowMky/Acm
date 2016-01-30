/*
ID: onlyazh1
LANG: C++
TASK: milk3
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
bool tag[1000000];
bool ans[30];
int A,B,C;

void Solve(int a,int b,int c){
    if(tag[a*10000+b*100+c]) return;
    tag[a*10000+b*100+c]=true;
    if(!a) ans[c]=true;
    if(a){
        Solve(a-min(a,B-b),b+min(a,B-b),c);
        Solve(a-min(a,C-c),b,c+min(a,C-c));
    }
    if(b){
        Solve(a+min(A-a,b),b-min(A-a,b),c);
        Solve(a,b-min(C-c,b),c+min(C-c,b));
    }
    if(c){
        Solve(a+min(A-a,c),b,c-min(A-a,c));
        Solve(a,b+min(B-b,c),c-min(B-b,c));
    }
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");
#endif
    cin>>A>>B>>C;
    Solve(0,0,C);
    bool flag=false;
    for(int i=0;i<=C;i++){
        if(ans[i]){
            if(flag) cout<<" ";
            cout<<i;
            flag=true;
        }
    }
    cout<<endl;
    return 0;
}
