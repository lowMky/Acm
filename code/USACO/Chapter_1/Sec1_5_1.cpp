/*
ID: onlyazh1
LANG: C++
TASK: numtri
*/

#include<set>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;
int a[1010][1010];
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");
#endif
    int R;
    cin>>R;
    for(int i=0;i<R;i++)
        for(int j=0;j<=i;j++)
            cin>>a[i][j];
    for(int i=1;i<R;i++)
        for(int j=0;j<=i;j++)
            if(!j) a[i][j]+=a[i-1][j];
            else a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
    int maxn=0;
    for(int i=0;i<R;i++)
        maxn=max(maxn,a[R-1][i]);
    cout<<maxn<<endl;
    return 0;
}
