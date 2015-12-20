#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll num[1000];
stack<int> S;
int n,m;
bool judge(ll mid){
    int sum=0,k=m;
    for(int i=n-1;i>=0;i--){
        if(num[i]>mid)
            return false;
        if(i+1==k&&k){
            k--;
            S.push(i);
            continue;
        }
        else if(sum+num[i]<=mid)
            sum+=num[i];
        else{
            if(k==0)
                return false;
            S.push(i);
            sum=num[i];
            k--;
        }
    }
    return true;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        m--;
        for(int i=0;i<n;i++)
            cin>>num[i];

        ll l=0,r=5000000000;
        vector<int> ans;
        while(l<r){
            ll mid=l+(r-l)/2;
            while(!S.empty())
                S.pop();
            if(judge(mid)){
                r=mid;
                ans.clear();
                for(int i=0,sz=S.size();i<sz;i++){
                    ans.push_back(S.top());
                    S.pop();
                }
            }
            else
                l=mid+1;
        }
        for(int i=0,j=0,sz=ans.size();i<n;i++){
            printf("%lld",num[i]);
            printf("%s",i==n-1?"\n":" ");

            if(i==ans[j]&&j<sz){
                printf("/ ");
                j++;
            }
        }
    }
    return 0;
}
