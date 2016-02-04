/*
ID: onlyazh1
LANG: C++
TASK: sort3
*/

#include<set>
#include<map>
#include<cmath>
#include<stack>
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
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
#endif
    int n;
    int A[1010],B[1010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];B[i]=A[i];
    }
    int ans=0;
    sort(B,B+n);
    for(int i=0;i<n;i++){
        if(A[i]==B[i]) continue;
        for(int j=i+1;j<n;j++){
            if(A[i]==B[j]&&A[j]==B[i]){
                swap(A[i],A[j]);ans++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(B[i]!=1) break;
        else if(A[i]!=1) ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}
