/*
ID: onlyazh1
LANG: C++
TASK: milk2
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
struct Line{
    int l,r;
    Line(){};
    Line(int _l,int _r){l=_l;r=_r;}
    bool operator <(const Line &L) const {
        return l<L.l;
    }
};

int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");
#endif
    int n;
    cin>>n;
    vector<Line> L;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        L.push_back(Line{l,r});
    }
    sort(L.begin(),L.end());
    int l=L[0].l,r=L[0].r;
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        if(L[i].l>r){
            ans2=max(ans2,L[i].l-r);
            l=L[i].l;r=L[i].r;
        }
        else
            r=max(r,L[i].r);
        ans1=max(ans1,r-l);
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
