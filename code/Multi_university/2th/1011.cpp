#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    int T;cin>>T;
    while(T--){
        int c1=0,c2=0;
        int n,num;cin>>n;
        for(int i=0;i<n;++i){
            cin>>num;
            if(num%2==1) c1++;
            c2=c2+(num)/2;
        }
        if(c1==0) cout<<(c2*2)<<endl;
        else cout<<(c2/c1)*2+1<<endl;
    }
    return 0;
}
