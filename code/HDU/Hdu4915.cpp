/*
ID: onlyazh1
LANG: C++
TASK: Remember the Word
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
typedef long long ll;

char s[1000100];
stack<char> S;

int solve(){
    while(!S.empty()) S.pop();
    int len=strlen(s);
    int cnt=0;bool tag=false;
    for(int i=0;i<len;i++){
        if(s[i]=='?')
            cnt++;
        else if(s[i]=='(')
            S.push(s[i]);
        else{
            if(S.empty()){
                if(cnt==0){
                    tag=true;
                    break;
                }
                else cnt--;
            }
            else S.pop();
        }
    }
    if(tag||cnt<(int)S.size()) return 0;
    else return cnt<=(int)S.size()+2?1:2;
}
int main(){
    //freopen("in.txt","r",stdin);

    while(cin>>s){
        int len=strlen(s);
        if(!len||len%2){
            cout<<"None"<<endl;
            continue;
        }
        if(s[0]=='?')
            s[0]='(';
        if(s[len-1]=='?')
            s[len-1]=')';
        /*
        if(s[0]==')'||s[len-1]=='('){
            cout<<
        }
        */
        int s1=solve();
        for(int p=0,q=len-1;p<q;p++,q--)
            swap(s[p],s[q]);
        for(int i=0;i<len;i++){
            if(s[i]=='?') continue;
            if(s[i]=='(') s[i]=')';
            else s[i]='(';
        }
        int s2=solve();
        //cout<<s1<<" "<<s2<<endl;
        if(!s1||!s2) cout<<"None"<<endl;
        else cout<< (s1+s2<=2?"Unique":"Many") <<endl;
    }
    return 0;
}
