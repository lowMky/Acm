/*
ID: onlyazh1
LANG: C++
TASK: Image Preview
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
int n,a,b,T;
char s[500010];
int c[1000010];

int bin1(int l,int r,int x){
    while(l<r){
        int mid=l+(r-l+1)/2;
        if((c[mid]+a*(mid-n))-(s[0]=='w'?b:1)<=x) l=mid;
        else r=mid-1;
    }
    return l;
}

int bin2(int l,int r,int x){
    while(l<r){
        int mid=l+(r-l)/2;
        if((c[mid]+a*(n-mid))-(s[0]=='w'?b:1)<=x) r=mid;
        else l=mid+1;
    }
    return r;
}

int main(){
    //ifstream cin("in.txt");
    int l,r;
    cin>>n>>a>>b>>T;
    cin>>s;
    if(T<1||(s[0]=='w'&&T<b+1)){
        cout<<0<<endl;return 0;
    }
    if(s[0]=='h')c[n]=1;
    else c[n]=b+1;
    l=r=n;
    for(int i=1;i<n;i++){
        c[i+n]=c[i-1+n]+a+1;
        if(s[i]=='w') c[i+n]+=b;
        if(c[i+n]<=T) r=i+n;
    }
    for(int i=n-1;i>0;i--){
        c[i]=c[i+1]+a+1;
        if(s[i]=='w') c[i]+=b;
        if(c[i]<=T) l=i;
    }
    int ans=max(r-n+1,n-l+1);
    for(int i=l;i<=r;i++){
        if(i<=n) ans=max(ans,1-i+(bin1(n,r,(T-c[i]))));
        else ans=max(ans,i+1-bin2(l,n,(T-c[i])));
    }
    ans=min(ans,n);
    cout<<ans<<endl;
    return 0;
}
