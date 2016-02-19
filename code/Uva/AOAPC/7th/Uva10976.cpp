#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool ok[20];
int ans[20];
bool P[40];
int n;
bool judge(int *a){
    if(P[a[0]+a[n-1]])
        return true;
    return false;
}

void next_permutation(int cnt,int *a){
    if(cnt==0){
        if(judge(a)){
            for(int i=0;i<n;i++){
                    printf("%d",a[i]);
                printf("%s",i<n-1?" ":"\n");
            }
        }
        return;
    }
    for(int i=2;i<=n;i++){
        if(!ok[i]&&P[i+a[n-cnt-1]]){
            a[n-cnt]=i;
            ok[i]=true;
            next_permutation(cnt-1,a);
            ok[i]=false;
        }
    }
}


int main(){
    P[2]=P[3]=P[5]=P[7]=P[11]=P[13]=P[17]=P[19]=P[23]=P[29]=P[31]=P[37]=true;
    int icase=0;
    while(cin>>n){
        memset(ans,0,sizeof(ans));
        memset(ok,0,sizeof(ok));
        ans[0]=1;
        if(icase)
            puts("");
        printf("Case %d:\n",++icase);
        next_permutation(n-1,ans);
    }
    return 0;
}
