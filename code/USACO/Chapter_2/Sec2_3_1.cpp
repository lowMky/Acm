/*
ID: onlyazh1
LANG: C++
TASK: prefix
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;
vector<string> P[30];
string S;
bool vis[200100];
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("prefix.in");
    ofstream cout("prefix.out");
#endif

    string tmp;
    while(cin>>tmp){
        if(tmp[0]=='.')  break;
        else P[tmp[0]-'A'].push_back(tmp);
    }
    while(cin>>tmp)
        S+=tmp;
    for(int i=-1,sz=S.size();i<sz-1;i++){
        if(i>=0&&!vis[i]) continue;
        for(int j=0,cnt=P[S[i+1]-'A'].size();j<cnt;j++){
            int len=P[S[i+1]-'A'][j].size();
            if(i+len>=sz) break;
            string sub=S.substr(i+1,len);
            if(sub==P[S[i+1]-'A'][j])
                vis[i+len]=true;
        }
    }
    int idx=S.size()-1;
    while(!vis[idx]&&idx>=0)
        idx--;
    cout<<idx+1<<endl;
    return 0;
}
