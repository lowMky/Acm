/*
ID: onlyazh1
LANG: C++
TASK: dualpal
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("dualpal.in");
    ofstream cout("dualpal.out");
#endif
    int s,n;
    vector<int> ans;
    cin>>n>>s;
    for(int i=s+1;;i++){
        int cnt=0;
        for(int j=2;j<=10;j++){
            int k=i;
            vector<int> tmp;
            while(k){
                tmp.push_back(k%j);
                k/=j;
            }
            bool flag=true;
            for(int p=0,q=tmp.size()-1;p<q;p++,q--)
                if(tmp[p]!=tmp[q]){
                    flag=false;break;
                }
            if(flag) cnt++;
            if(cnt==2){
                ans.push_back(i);
                break;
            }
        }
        if(ans.size()==n) break;
    }
    for(int i=0,sz=ans.size();i<sz;i++)
        cout<<ans[i]<<endl;
    return 0;
}
