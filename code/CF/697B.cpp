#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll inf=1e18;
const int MOD=1e9;

char s[10010];
char ans[10010];

int find(){
    for(int i=0,len=strlen(s);i<len;++i)
        if(s[i]=='.') return i;
}

int fun(){
    int cnt=0;
    for(int i=2,len=strlen(s);i<len;++i){
        if(s[i]=='0') cnt++;
        else return cnt;
    }
}

int main(){
//    ifstream cin("in.txt");
    cin>>s;
    int mi=0;bool tag=false;
    for(int i=0,len=strlen(s);i<len;++i){
        if(s[i]=='e'){
            tag=true;
            continue;
        }

        if(!tag) continue;
        mi=mi*10+s[i]-'0';
    }

    if(s[0]=='0')
        mi-=fun();
    else mi+=find();

    int cc=0;bool flag=false;
    for(int i=0,len=strlen(s);i<=len;++i){
        if(s[i]=='.') continue;
        if(s[i]=='e') break;
        if(flag||(s[i]>'0'&&s[i]<='9')){
            flag=true;
            ans[cc++]=s[i];
        }
    }
    ans[cc]=0;
    for(int i=cc-1;i>=0;--i)
        if(ans[i]=='0') ans[i]=0;
        else break;

//    cout<<ans<<"  "<<mi<<endl;
    if(strlen(ans)==0)
        cout<<"0"<<endl;
    else if(mi>0){
        if(strlen(ans)<=mi){
            cout<<ans;
            for(int i=strlen(ans);i<mi;++i)
                cout<<"0";
            cout<<endl;
        }
        else{
            for(int i=0;i<mi;++i)
                cout<<ans[i];
            cout<<".";
            for(int i=mi,len=strlen(ans);i<len;++i)
                cout<<ans[i];
            cout<<endl;
        }
    }
    else{
        cout<<"0.";
        while(mi++)
            cout<<"0";
        for(int i=0,len=strlen(ans);i<len;++i)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}


