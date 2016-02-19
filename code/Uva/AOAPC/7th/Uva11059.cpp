#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
int main(){
    int n;
    while(cin>>n){
        ans.clear();
        for(int i=n+1;i<=2*n;i++){
            if((i*n)%(i-n)==0){
                ans.push_back(i);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0,sz=ans.size();i<sz;i++){
            cout<<"1/"<<n<<" = "<<"1/"<<(ans[i]*n)/(ans[i]-n)<<" + "<<"1/"<<ans[i]<<endl;
        }
    }
    return 0;
}
