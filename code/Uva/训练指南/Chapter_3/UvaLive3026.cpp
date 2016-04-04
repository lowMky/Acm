/*
ID: onlyazh1
LANG: C++
TASK: Remember the Word
*/

#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
typedef long long ll;
char s[1001000];
int f[1001000];
int main(){
    //ifstream cin("in.txt");
    int icase=0,len;
    while(cin>>len&&len){
        cin>>s;
        f[0]=f[1]=0;
        for(int i=1;i<len;i++){
            int j=f[i];
            while(j&&s[i]!=s[j])
                j=f[j];
            f[i+1]= (s[i]==s[j]?j+1:0);
        }

        //if(icase) cout<<endl;
        cout<<"Test case #"<<++icase<<endl;
        for(int i=1;i<=len;i++)
            if(f[i]&&i%(i-f[i])==0)
                cout<<i<<" "<<i/(i-f[i])<<endl;
        cout<<endl;
    }
    return 0;
}
