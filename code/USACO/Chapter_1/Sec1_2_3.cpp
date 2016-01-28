/*
ID: onlyazh1
LANG: C++
TASK: namenum
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
int d[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("namenum.in");
    ifstream fcin("dict.txt");
    ofstream cout("namenum.out");
#endif
    ll n;
    string s;
    vector<string> S;
    cin>>n;
    while(fcin>>s){
        ll num=0;
        for(int i=0;i<s.length();i++)
            num=num*10+d[s[i]-'A'];
        if(num==n) S.push_back(s);
    }
    sort(S.begin(),S.end());
    if(S.size())
        for(int i=0,sz=S.size();i<sz;i++)
            cout<<S[i]<<endl;
    else
        cout<<"NONE"<<endl;
    return 0;
}
