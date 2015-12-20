#include<bits/stdc++.h>

using namespace std;

int a[200100];
int l[200100];
int r[200100];
map<int,int> cur;
bool tag;
int n;

bool judge(int i,int ll,int rr){
    if((l[i]==-1||l[i]<ll)&&(r[i]==-1||r[i]>rr))
        return true;
    return false;
}

void fun(){
    //memset(l,-1,sizeof(l));
    //memset(r,-1,sizeof(r));
    cur.clear();
    for(int i=0;i<n;i++){
        if(cur.count(a[i]))
            l[i]=cur[a[i]];
        else
            l[i]=-1;
        cur[a[i]]=i;
    }

    cur.clear();
    for(int i=n-1;i>=0;i--){
        if(cur.count(a[i]))
            r[i]=cur[a[i]];
        else
            r[i]=-1;
        cur[a[i]]=i;
    }
    //for(int i=0;i<n;i++)
        //cout<<l[i]<<" "<<r[i]<<endl;
}

void solve(int l,int r){
    if(tag||l>=r)
        return ;
    int mid=-1;
    int len=(r-l)/2;
    for(int i=0;i<=len;i++){
        if(judge(l+i,l,r)){
            mid=l+i;
            break;
        }
        else if(judge(r-i,l,r)){
            mid=r-i;
            break;
        }
    }
    if(mid==-1){
        tag=true;
        return;
    }
    else{
        solve(l,mid-1);
        solve(mid+1,r);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        tag=false;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        fun();
        solve(0,n-1);
        printf("%s\n",tag?"boring":"non-boring");
    }
    return 0;
}
