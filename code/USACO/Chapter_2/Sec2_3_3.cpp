/*
ID: onlyazh1
LANG: C++
TASK: zerosum
*/
#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;

vector<string> S;
char s[100];


int Cal(){
    deque<int> sta;
    deque<int> op;
    for(int i=0,sz=strlen(s);i<sz;i++){
        if(isdigit(s[i]))
            sta.push_back(s[i]-'0');
        else if(s[i]==' '){
            int t=sta.back();
            sta.pop_back();
            sta.push_back(t*10+s[i+1]-'0');
            i++;
        }
        else op.push_back(s[i]);
    }
    //cout<<op.size()<<endl;
    //cout<<sta.size()<<endl;

    while(!op.empty()){
        char opt=op.front();op.pop_front();
        int a=sta.front();sta.pop_front();
        int b=sta.front();sta.pop_front();
        if(opt=='+') sta.push_front(a+b);
        if(opt=='-') sta.push_front(a-b);
    }
    //cout<<sta.top()<<endl;
    return sta.front();
}

void DFS(int lef){
    if(!lef){
        if(!Cal()){
            string tmp=s;
            S.push_back(tmp);
        }
        return;
    }

    s[lef*2-1]='+';DFS(lef-1);
    s[lef*2-1]='-';DFS(lef-1);
    s[lef*2-1]=' ';DFS(lef-1);
}
int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("zerosum.in");
    ofstream cout("zerosum.out");
#endif

    int n;cin>>n;
    for(int i=0;i<n;i++)
        s[i*2]=i+1+'0';
    DFS(n-1);
    sort(S.begin(),S.end());
    for(int i=0,sz=S.size();i<sz;i++)
        cout<<S[i]<<endl;
    return 0;
}
