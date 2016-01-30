/*
ID: onlyazh1
LANG: C++
TASK: ariprog
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
struct Node{
    int a,b;
    Node(){};
    Node(int _a,int _b){a=_a;b=_b;};
    bool operator <(const Node & A) const{
        if(b<A.b) return true;
        else if(b==A.b) return a<A.a;
        else return false;
    };
};

vector<int> V;
int n,m;
bool tag[150000];
vector<Node> ans;
bool Solve(int a,int b,int n){
    if(n<=0)
        return true;
    if(a+b<=2*m*m&&tag[a+b]) return Solve(a+b,b,n-1);
    else return false;
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("ariprog.in");
    ofstream cout("ariprog.out");
#endif
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        for(int j=i;j<=m;j++){
            if(!tag[i*i+j*j])
                V.push_back(i*i+j*j);
            tag[i*i+j*j]=true;
        }
    sort(V.begin(),V.end());
    for(int i=0,sz=V.size();i<sz;i++)
        for(int j=i+1;j<sz;j++)
            if(Solve(V[i],V[j]-V[i],n-1))
                ans.push_back(Node(V[i],V[j]-V[i]));
    sort(ans.begin(),ans.end());
    if(ans.size())
        for(int i=0,sz=ans.size();i<sz;i++)
            cout<<ans[i].a<<" "<<ans[i].b<<endl;
    else
        cout<<"NONE"<<endl;
    return 0;
}
