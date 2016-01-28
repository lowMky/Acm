/*
ID: onlyazh1
LANG: C++
TASK: beads
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL

int L_find(string s,int idx,char ch){
    for(int i=idx;i>=0;i--)
        if(s[i]!=ch&&s[i]!='w')
            return i+1;
    return 0;
}

int R_find(string s,int idx,char ch){
    for(int i=idx,sz=s.length();i<sz;i++)
        if(s[i]!=ch&&s[i]!='w')
            return i-1;
    return s.length();
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("beads.in");
    ofstream cout("beads.out");
#endif
    int n;
    string str;
    cin>>n;
    cin>>str;
    str=str+str+str;

    int ans=0;
    for(int idx=n;idx<2*n;idx++){
        ans=max(ans,R_find(str,idx+1,'r')-L_find(str,idx,'b')+1);
        ans=max(ans,R_find(str,idx+1,'b')-L_find(str,idx,'r')+1);
    }
    cout<<min(ans,n)<<endl;
    return 0;
}
