/*
ID: onlyazh1
LANG: C++
TASK: test
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=4001000;


int phi[maxn];

void phi_table(int n){
    for(int i=0;i<n;i++) phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++)
        if(!phi[i])
            for(int j=i;j<=n;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
}

ll f[maxn];
bool not_prime[maxn];

void get_prime(int n){
    phi_table(n);
    for(int i=1;i<=n;i++)
        for(int j=2*i;j<=n;j+=i)
            f[j]+=ll(i)*phi[j/i];
    for(int i=2;i<=n;i++)
        f[i]+=f[i-1];
}

int main(){
    get_prime(maxn-1);

    int n;
    while(cin>>n&&n)
        cout<<f[n]<<endl;
    return 0;
}
