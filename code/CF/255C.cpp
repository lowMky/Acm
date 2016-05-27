/*
ID: onlyazh1
LANG: C++
TASK: test
*/

#include<bits/stdc++.h>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long ll;
int num[4010];
int cnt[4010];
bool tag[4010];
int rec[4010];
int crec;
map<int,int> M;

int main(){
    //freopen("in.txt","r",stdin);
    int n,idx=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&num[i]);
        if(M.find(num[i])==M.end())
            M[num[i]]=idx++;
        else cnt[M[num[i]]]++;
    }
    int ans=0;
    for(int i=0;i<idx;++i)
        ans=max(ans,cnt[i]+1);
    for(int i=0;i<n;++i){
        crec=0;
        for(int j=0;j<idx;++j){
            tag[j]=true;
            cnt[j]=0;
        }
        for(int j=i+1;j<n;++j){
            if(num[j]==num[i]){
                for(int k=0;k<crec;++k)
                    tag[rec[k]]=true;
                crec=0;
            }
            else{
                if(tag[M[num[j]]]){
                    cnt[M[num[j]]]++;
                    tag[M[num[j]]]=false;
                    rec[crec++]=M[num[j]];
                }
            }
        }
        for(int j=0;j<idx;++j){
            if(j==M[num[i]]) continue;
            ans=max(ans,cnt[j]*2+(tag[j]?1:0));
        }
    }
    cout<<ans<<endl;
    return 0;
}
