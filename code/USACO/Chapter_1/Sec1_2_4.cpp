/*
ID: onlyazh1
LANG: C++
TASK: palsquare
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
    ifstream cin("palsquare.in");
    ofstream cout("palsquare.out");
#endif
    int bas,cnt=0;
    vector<string> ans1,ans2;
    cin>>bas;
    for(int i=1;i<=300;i++){
        int k=i*i;
        string s;
        vector<int> t;
        while(k){
            if(k%bas<10)
                s+=(k%bas)+'0';
            else
                s+=(k%bas)-10+'A';
            k/=bas;
        }
        bool flag=true;
        for(int p=0,q=s.size()-1;p<q;p++,q--)
            if(s[p]!=s[q]){
                flag=false;
                break;
            }
        if(flag){
            int d=i;
            string t;
            while(d){
                if(d%bas<10)
                    t+=(d%bas)+'0';
                else
                    t+=(d%bas)-10+'A';
                d/=bas;
            }
            for(int p=0,q=t.size()-1;p<q;p++,q--)
                swap(t[p],t[q]);
            ans1.push_back(t);
            ans2.push_back(s);
        }
    }
    for(int i=0,sz=ans1.size();i<sz;i++)
        cout<<ans1[i]<<" "<<ans2[i]<<endl;
    return 0;
}
