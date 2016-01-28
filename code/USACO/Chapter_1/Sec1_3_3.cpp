/*
ID: onlyazh1
LANG: C++
TASK: crypt1
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
vector<int> V;
int n;
bool Jud(int t){
    while(t){
        bool flag=false;
        for(int i=0;i<n;i++)
            if(V[i]==t%10)
                flag=true;
        if(!flag)
            return false;
        t/=10;
    }
    return true;
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");
#endif
    int t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        V.push_back(t);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int p=0;p<n;p++){
                    for(int q=0;q<n;q++){
                        int s1=(V[i]*100+V[j]*10+V[k])*V[p];
                        int s2=(V[i]*100+V[j]*10+V[k])*V[q];
                        int s3=(V[i]*100+V[j]*10+V[k])*(10*V[p]+V[q]);
                        if(s1>999||s2>999||s3>9999) continue;
                        if(Jud(s1)&&Jud(s2)&&Jud(s3))
                            ans++;

                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
