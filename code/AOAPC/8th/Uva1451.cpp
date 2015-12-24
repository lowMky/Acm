#include<bits/stdc++.h>

using namespace std;

char str[100100];
int sum[100100];
int S[100100];
double Gra[100100];

double fun(int i,int j){
    return (sum[j]-sum[i])*1.0/(j-i);
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int n,L;
        cin>>n>>L;
        cin>>str;
        sum[0]=0;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+str[i-1]-'0';

        int base=0,top=-1;
        int l=0,r=L;

        double ans=(sum[L]-sum[0])*1.0/L;
        for(int i=L;i<=n;i++){
            int j=i-L;
            while(top>base&&fun(S[top],j)<=fun(S[top-1],j))
                top--;
            S[++top]=j;
            while(base<top&&fun(S[base+1],i)>=fun(S[base],i))
                base++;
            double tmp=fun(S[base],i);
            if(ans<tmp||(tmp==ans&&(r-l>i-S[base]))){
                l=S[base];r=i;ans=tmp;
            }
        }
        cout<<l+1<<" "<<r<<endl;
    }
    return 0;

}
