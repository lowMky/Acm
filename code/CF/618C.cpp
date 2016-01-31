/*
ID: onlyazh1
LANG: C++
TASK: pprime
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

struct Point{
    ll x,y;
    int tag;
};
Point p[100100];

ll cross(const Point &a,const Point &b){
    return a.x*b.y-b.x*a.y;
}

bool cmp(const Point &a, const Point &b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main(){
/*
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
#endif
*/
    //ifstream cin("in.txt");
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].tag=i+1;
    }
    sort(p,p+n,cmp);

    int a=p[0].tag,b=p[1].tag;
    Point A;
    A.x=p[0].x-p[1].x;
    A.y=p[0].y-p[1].y;
    for(int i=2;i<n;i++){
        Point B;
        B.x=p[i].x-p[1].x;
        B.y=p[i].y-p[1].y;
        if(cross(A,B)){
            cout<<a<<" "<<b<<" "<<p[i].tag<<endl;
            break;
        }
    }
    return 0;
}
