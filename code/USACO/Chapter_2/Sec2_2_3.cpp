/*
ID: onlyazh1
LANG: C++
TASK: runround
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>

using namespace std;

//#define LOCAL
typedef unsigned long long ll;

ll ans=0,m;
int len=0;
bool vis[10];
bool tag[20];

bool Jud(ll x){
    vector<int> tmp;
    memset(tag,false,sizeof(tag));
    while(x){
        ll t=x%10;
        tmp.push_back(int(t));
        x/=10;
    }
    for(int p=0,q=tmp.size()-1;p<q;p++,q--)
        swap(tmp[p],tmp[q]);
    int idx=0;
    for(int i=0,sz=tmp.size();i<sz;i++){
        idx=(idx+tmp[idx])%sz;
        if(tag[idx]) return false;
        else tag[idx]=true;
    }
    return true;
}

void DFS(int idx,ll num,ll sum){
    if(ans>m)
        return ;
    if(!idx){
        if(sum%len!=0)
            return;
        if(Jud(num))
            ans=max(ans,num);
        return;
    }
    for(int i=1;i<=9;i++){
        if(!vis[i]){
            vis[i]=true;
            DFS(idx-1,num*10+i,sum+i);
            vis[i]=false;
        }
    }
}

int getlen(ll x){
    int len=0;
    while(x){
        x/=10;
        len++;
    }
    return len;
}

void Solve(ll x){
    len=getlen(x);
    while(ans<=x){
        DFS(len,0,0);
        len++;
    }
}

int main(){

#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("runround.in");
    ofstream cout("runround.out");
#endif
    cin>>m;
    Solve(m);
    cout<<ans<<endl;
    return 0;
}
