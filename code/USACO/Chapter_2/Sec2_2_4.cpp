/*
ID: onlyazh1
LANG: C++
TASK: lamps
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

//#define LOCAL
typedef unsigned long long ll;
vector<int> on;
vector<int> off;
vector<string> S;
char str[200];
int n,c;

bool Jud(){
    for(int i=0,sz=on.size();i<sz;i++)
        if(str[on[i]-1]=='0') return false;
    for(int i=0,sz=off.size();i<sz;i++)
        if(str[off[i]-1]=='1') return false;
    return true;
}

void op1(){
    for(int i=0;i<n;i++)
        str[i]='1'-str[i]+'0';
}

void op2(){
    for(int i=0;i<n;i+=2)
        str[i]='1'-str[i]+'0';
}
void op3(){
    for(int i=1;i<n;i+=2)
        str[i]='1'-str[i]+'0';
}
void op4(){
    for(int i=0;i<n;i+=3)
        str[i]='1'-str[i]+'0';
}
void DFS(int idx){
    if(!idx){
        if(Jud()){
            string s=str;
            S.push_back(s);
        }
        return;
    }
    op1();DFS(idx-1);op1();
    op2();DFS(idx-1);op2();
    op3();DFS(idx-1);op3();
    op4();DFS(idx-1);op4();
}

int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("lamps.in");
    ofstream cout("lamps.out");
#endif

    cin>>n>>c;
    int t;
    while(cin>>t){
        if(t==-1)
            break;
        else on.push_back(t);
    }
    while(cin>>t){
        if(t==-1)
            break;
        else off.push_back(t);
    }
    for(int i=0;i<n;i++)
        str[i]='1';

    c=min(c,4);
    DFS(c);
    if(S.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    sort(S.begin(),S.end());
    int cnt=1;
    for(int i=1;i<S.size();i++)
        if(S[i]!=S[i-1])
            S[cnt++]=S[i];
    for(int i=0;i<cnt;i++)
        cout<<S[i]<<endl;
    return 0;
}
