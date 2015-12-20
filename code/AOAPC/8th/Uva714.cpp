#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int p[100100];
int q[100100];

int main(){
    int T,icase=0;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>q[i];
        int l=0,r=0,sum=0;
        while(l<n){
            sum+=p[r%n];
            if(sum<q[r%n]){
                l=r=r+1;
                sum=0;
            }
            else{
                sum-=q[r%n];
                r++;
            }
            if(r-l==n)
                break;
        }
        printf("Case %d: ",++icase);
        if(r-l==n)
            printf("Possible from station %d\n",l+1);
        else
            printf("Not possible\n");
    }
    return 0;
}
