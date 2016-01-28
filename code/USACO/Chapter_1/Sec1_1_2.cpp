/*
ID: onlyazh1
LANG: C++
TASK: gift1
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    //ifstream cin("in.txt");
    //ofstream cout("out.txt");

    ifstream cin("gift1.in");
    ofstream cout("gift1.out");

    int n;

    while(cin>>n){
        map<string,int> M;
        vector<string> S;
        int ha[20],gi[20];
        string str;

        for(int i=0;i<n;i++){
            cin>>str;
            M[str]=i;
            gi[M[str]]=0;
            S.push_back(str);
        }
        for(int i=0;i<n;i++){
            int t;
            string tstr;
            cin>>str;
            cin>>ha[M[str]]>>t;
            for(int j=0;j<t;j++){
                cin>>tstr;
                gi[M[tstr]]+=ha[M[str]]/t;
                gi[M[str]]-=ha[M[str]]/t;
            }
        }
        for(int i=0;i<n;i++)
            cout<<S[i]<<" "<<gi[M[S[i]]]<<endl;
    }
    return 0;
}
