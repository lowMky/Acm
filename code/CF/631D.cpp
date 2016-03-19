/*
ID: onlyazh1
LANG: C++
TASK: Low Cost Air Travel
*/

#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=200100;
int cntt,cnts;
char Tc[maxn];ll Tcc[maxn];
char Sc[maxn];ll Scc[maxn];
int nex[maxn];
void kmp_pre(){
    nex[1]=nex[2]=1;
    for(int i=2;i<cnts-1;i++){
        int j=nex[i];
        while(j!=1&&(Sc[i]!=Sc[j]||Scc[i]!=Scc[j])) j=nex[j];
        nex[i+1]=(Sc[i]==Sc[j]&&Scc[i]==Scc[j])?j+1:1;
    }
}

ll kmp_cnt(){
    kmp_pre();int j=1,ans=0;
    for(int i=1;i<cntt-1;i++){
        while(j!=1&&(Tc[i]!=Sc[j]||Tcc[i]!=Scc[j])) j=nex[j];
        if(Tc[i]==Sc[j]&&Tcc[i]==Scc[j]) j++;
        if(j==cnts-1){
            int l=i-cnts+2;int r=i+1;
            if(Tc[l]==Sc[0]&&Tcc[l]>=Scc[0]&&Tc[r]==Sc[cnts-1]&&Tcc[r]>=Scc[cnts-1])
                ans++;
            j=nex[j];
        }
    }
    return ans;
}

int main(){
    //ifstream cin("in.txt");
    int n,m;cin>>n>>m;
    cntt=cnts=0;
    ll t;char ch;
    while(n--){
        cin>>t>>ch>>ch;
        if(!cntt||ch!=Tc[cntt-1]){
            Tc[cntt]=ch;Tcc[cntt++]=t;
        }
        else Tcc[cntt-1]+=t;
    }
    while(m--){
        cin>>t>>ch>>ch;
        if(!cnts||ch!=Sc[cnts-1]){
            Sc[cnts]=ch;Scc[cnts++]=t;
        }
        else Scc[cnts-1]+=t;
    }
    ll ans=0;
    if(cnts==1){
        for(int i=0;i<cntt;i++)
            if(Tc[i]==Sc[0]) ans+=max(0LL,Tcc[i]-Scc[0]+1);
    }
    else if(cnts==2){
        for(int i=0;i<cntt-1;i++)
            if(Tc[i]==Sc[0]&&Tcc[i]>=Scc[0]&&Tc[i+1]==Sc[1]&&Tcc[i+1]>=Scc[1])
                ans++;
    }
    else ans=kmp_cnt();
    cout<<ans<<endl;
    return 0;
}
