#include<bits/stdc++.h>

using namespace std;
struct Inv{
    int l,r,id;
}inv[2][5010];
int ans[2][5010];
int n;

bool cmp(Inv a,Inv b){
    return a.r<b.r;
}

bool solve(Inv *A,int *ans){
    sort(A,A+n,cmp);
    bool flag[5010];
    memset(flag,0,sizeof(flag));
    int s=1;
    for(int i=0;i<n;i++){
        bool tag=false;
        for(int k=A[i].l;k<=A[i].r;k++){
            if(!flag[k]){
                flag[k]=tag=true;
                ans[A[i].id]=k;
                break;
            }
        }
        if(!tag)
            return false;
    }
    return true;
}

int main(){

    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&inv[0][i].l,&inv[1][i].l);
            scanf("%d%d",&inv[0][i].r,&inv[1][i].r);
            inv[0][i].id=inv[1][i].id=i;
        }
        if(solve(inv[0],ans[0])&&solve(inv[1],ans[1])){
            for(int i=0;i<n;i++)
                printf("%d %d\n",ans[0][i],ans[1][i]);
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
