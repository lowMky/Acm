/*
ID: onlyazh1
LANG: C++
TASK: transform
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
//#define LOCAL

int n,ans;
char m[15][15];
char res[15][15];
void Rotate(){
    char tmp[15][15];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tmp[j][n-1-i]=m[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j]=tmp[i][j];
}

void Ref(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n/2;j++)
            swap(m[i][j],m[i][n-1-j]);
}
void Cmp(int x){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(m[i][j]!=res[i][j])
                return;
    ans=min(ans,x);
}

int main(){
#ifdef LOCAL
    ifstream cin("in.txt");
    //ofstream cout("out.txt");
#else
    ifstream cin("transform.in");
    ofstream cout("transform.out");
#endif
    ans=7;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i];
    for(int i=0;i<n;i++)
        cin>>res[i];
    Cmp(6);
    Ref();
    Cmp(4);
    for(int i=1;i<=3;i++){
        Rotate();
        Cmp(5);
    }
    Rotate();
    Ref();
    for(int i=1;i<=3;i++){
        Rotate();
        Cmp(i);
    }
    cout<<ans<<endl;
    return 0;
}
