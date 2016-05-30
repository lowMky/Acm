#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll MOD=1e9+7;

ll l,r;
int p,n;
int prime[110];
int a[3000100];
int f[3000100];
bool flag[3000100];

void getPrime(int P)
{
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=P; i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1; j<=prime[0]&&prime[j]<=P/i; j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void dfs(int x,int idx)
{
    a[n++]=x;
    for(int i=idx; i<=prime[0]; ++i)
    {
        if(x*1ll*prime[i]>r) break;
        dfs(x*prime[i],i);
    }
}

int main()
{
//    ifstream cin("in.txt");
    cin>>l>>r>>p;
    getPrime(p);

    n=0;
    dfs(1,1);
    sort(a,a+n);
//    cout<<n<<endl;
//    for(int i=0; i<n; ++i)
//        cout<<a[i]<<endl;

    memset(f,0x3f3f3f3f,sizeof(f));
    f[0]=0;
    int ans=0;
    for(int i=2;i<=p;++i)
    {
        int ptr=0;
        for(int j=1;j<n;++j)
        {
            while(ptr<n&&a[ptr]*i<a[j])
                ptr++;
            if(ptr==n) break;
            if(a[ptr]*i==a[j]){
                f[j]=min(f[j],f[ptr]+1);
//                cout<<"a[ptr]="<<a[ptr]<<" a[j]="<<a[j]<<endl;
//                cout<<j<<" "<<f[j]<<endl;
                if(f[j]+i<=p&&a[j]<=r&&a[j]>=l&&!flag[j]){
                    ans++;flag[j]=true;
                }
            }
        }
    }
//    cout<<a[1]<<" "<<f[1]<<endl;
    cout<<ans<<endl;
    return 0;
}
