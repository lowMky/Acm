#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<set>
using namespace std;

typedef long long ll;

int num[110];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int T;cin>>T;
    while(T--){
        int n,m,x,y;
        cin>>n>>m;
        memset(num,-1,sizeof(num));
        for(int i=0;i<m;++i){
            cin>>x>>y;
            num[x-1]=y;
        }
        if(num[0]==-1) num[0]=100;
        if(num[1]==-1) num[1]=min(num[0],100);
        for(int i=2;i<n;++i)
            if(num[i]!=-1)
                for(int j=i-1;j>=2&&num[j]==-1;--j)
                    num[j]=num[i];

        for(int i=0;i<n;++i)
            if(num[i]==-1)
                num[i]=0;

        int sum=0;
        for(int i=0;i<n;++i)
            sum+=num[i];
        int gg=gcd(num[0]+num[1],sum);
        cout<<(num[0]+num[1])/gg<<"/"<<sum/gg<<endl;
    }

    return 0;
}
