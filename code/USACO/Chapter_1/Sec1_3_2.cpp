/*
ID: onlyazh1
LANG: C++
TASK: barn1
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;
bool tag[250];
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
#endif
    int m,s,c;
    cin>>m>>s>>c;
    int t,p=s,q=0;
    for(int i=0;i<c;i++){
        cin>>t;tag[t]=true;
        p=min(p,t);q=max(q,t);
    }
    vector<int> V;
    int len=0;
    for(int i=p+1;i<=q;i++){
        if(!tag[i]) len++;
        else{
            if(len) V.push_back(len);
            len=0;
        }
    }
    sort(V.begin(),V.end());
    int ans=c;
    for(int i=0;V.size()>=m+i;i++)
        ans+=V[i];
    cout<<ans<<endl;
    return 0;
}
