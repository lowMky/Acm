#include<bits/stdc++.h>

using namespace std;

int hu[1000100];
int hd[1000100];
int l[1000100];
int r[1000100];

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>hd[i];
        for(int i=0;i<n;i++)
            cin>>hu[i];
        l[0]=hu[0];
        r[n-1]=hu[n-1];
        for(int i=1;i<n;i++){
            if(hd[i]>=l[i-1])
                l[i]=hd[i];
            else
                l[i]=min(l[i-1],hu[i]);
        }

        for(int i=n-2;i>=0;i--){
            if(hd[i]>=r[i+1])
                r[i]=hd[i];
            else
                r[i]=min(r[i+1],hu[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
            ans+=(max(0,min(l[i],r[i])-hd[i]));
        cout<<ans<<endl;
    }
    return 0;
}
