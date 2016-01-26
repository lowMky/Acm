/*
ID: onlyazh1
LANG: C++
TASK: ride
*/

#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ifstream cin("ride.in");
    ofstream cout("ride.out");

    string a,b;
    while(cin>>a>>b){
        int t1=1,t2=1;
        for(int i=0,sz=a.length();i<sz;i++)
            t1*=(a[i]-'A'+1);
        for(int i=0,sz=b.length();i<sz;i++)
            t2*=(b[i]-'A'+1);
        if(t1%47==t2%47)
            cout<<"GO"<<endl;
        else
            cout<<"STAY"<<endl;
    }
    return 0;
}
