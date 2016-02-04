/*
ID: onlyazh1
LANG: C++
TASK: frac1
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
struct Node{
    int a,b;
    Node(){};
    Node(int _a,int _b){
        a=_a,b=_b;
    };
    bool operator <(const Node &A)const{
        return a*A.b<A.a*b;
    };
};
vector<Node> ans;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
#endif
    int n;cin>>n;
    ans.push_back(Node(0,1));
    ans.push_back(Node(1,1));
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(gcd(i,j)==1)
                ans.push_back(Node(j,i));
    sort(ans.begin(),ans.end());
    for(int i=0,sz=ans.size();i<sz;i++)
        cout<<ans[i].a<<"/"<<ans[i].b<<endl;
    return 0;
}
