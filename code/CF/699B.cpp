#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > P;
char G[1010][1010];

int c1[1010];
int c2[1010];

int main()
{
    int n,m,cnt=0;cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>G[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(G[i][j]=='*'){
                c1[i]++;c2[j]++;
                cnt++;
            }
    int c=0,r=0;bool flag=false;
    for(int i=0;i<n&&!flag;++i)
        for(int j=0;j<m;++j){
            if((G[i][j]=='*'&&(c1[i]+c2[j]==cnt+1))||(G[i][j]!='*'&&(c1[i]+c2[j]==cnt))){
                flag=true;r=i;c=j;break;
            }
        }
    if(!flag){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<r+1<<" "<<c+1<<endl;
    }
    return 0;
}
