#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        int num[1000100];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>num[i];
        int L=0,ans=0;
        set<int> S;
        for(int i=0;i<n;i++){
            while(S.find(num[i])!=S.end()){
                S.erase(num[L++]);
            }
            S.insert(num[i]);
            ans=max(ans,(int)S.size());
        }
        printf("%d\n",ans);
    }
    return 0;
}
