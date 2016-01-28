/*
ID: onlyazh1
LANG: C++
TASK: combo
*/
#include<set>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL
typedef long long ll;
set<int> S;
int n;
int A[3],B[3];
void Solve(int *A){
    for(int i=-2;i<=2;i++)
        for(int j=-2;j<=2;j++)
            for(int k=-2;k<=2;k++){
                int d=((A[0]+i+n)%n)*10000+((A[1]+j+n)%n)*100+(A[2]+k+n)%n;
                S.insert(d);
            }
}
int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("combo.in");
    ofstream cout("combo.out");
#endif

    cin>>n;
    cin>>A[0]>>A[1]>>A[2];
    cin>>B[0]>>B[1]>>B[2];

    Solve(A);
    Solve(B);
    cout<<S.size()<<endl;
    return 0;
}
