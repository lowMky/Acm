#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int num[100100];
int last[100100];
bool tag[100100];
int main(){

    //freopen("in.txt","r",stdin);

    int T;
    cin>>T;
    while(T--){
        int n,s;
        cin>>s>>n;
        for(int i=0;i<n;i++)
            cin>>num[i];

        memset(last,-1,sizeof(last));
        memset(tag,0,sizeof(tag));

        for(int l=-100000,r=0;r<n;r++){
            if(last[num[r]-0]==-1){
                last[num[r]-0]=r;
            }
            else{
                for(int k=max(l,r-s+1);k<=last[num[r]-0];k++)
                    if(!tag[(k+s)%s]){
                        //cout<<"**"<<(k%s)<<"**"<<endl;
                        tag[(k+s)%s]=true;
                    }
                l=last[num[r]-0]+1;
                last[num[r]-0]=r;
            }
        }
        int cnt=0;
        for(int i=0;i<s;i++)
            if(tag[i])
                cnt++;
        cout<<s-cnt<<endl;
    }
    return 0;
}
