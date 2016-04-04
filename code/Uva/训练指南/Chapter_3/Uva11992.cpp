/*
ID: onlyazh1
LANG: C++
TASK: Delivery Bears
*/

#include<iostream>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<vector>
#include<sstream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
typedef long long ll;
const int maxn=100100;
const int INF=1e9;
struct Node{
    bool tt1,tt2;
    int t1,t2;
    int sum,mina,maxa;
}Tr[25][maxn<<2];

void PushUp(int row,int rt){
    Tr[row][rt].sum=Tr[row][rt<<1].sum+Tr[row][rt<<1|1].sum;
    Tr[row][rt].mina=min(Tr[row][rt<<1].mina,Tr[row][rt<<1|1].mina);
    Tr[row][rt].maxa=max(Tr[row][rt<<1].maxa,Tr[row][rt<<1|1].maxa);
}

void PushDown(int row,int rt,int len){
    if(Tr[row][rt].tt2){
        int x=Tr[row][rt].t2;
        Tr[row][rt<<1].sum=(len-len/2)*x;
        Tr[row][rt<<1|1].sum=(len/2)*x;
        Tr[row][rt<<1].maxa=Tr[row][rt<<1].mina=x;
        Tr[row][rt<<1|1].maxa=Tr[row][rt<<1|1].mina=x;
        Tr[row][rt<<1].t2=Tr[row][rt<<1|1].t2=Tr[row][rt].t2;
        Tr[row][rt<<1].tt2=Tr[row][rt<<1|1].tt2=Tr[row][rt].tt2;
        Tr[row][rt].t2=0;Tr[row][rt].tt2=false;
        Tr[row][rt<<1].t1=Tr[row][rt<<1|1].t1=0;
        Tr[row][rt<<1].tt1=Tr[row][rt<<1|1].tt1=false;
    }
    if(Tr[row][rt].tt1){
        int x=Tr[row][rt].t1;
        Tr[row][rt<<1].sum+=(len-len/2)*x;
        Tr[row][rt<<1|1].sum+=(len/2)*x;
        Tr[row][rt<<1].maxa+=x;Tr[row][rt<<1].mina+=x;
        Tr[row][rt<<1|1].maxa+=x;Tr[row][rt<<1|1].mina+=x;
        Tr[row][rt<<1].t1+=Tr[row][rt].t1;Tr[row][rt<<1|1].t1+=Tr[row][rt].t1;
        Tr[row][rt<<1].tt1=Tr[row][rt<<1|1].tt1=Tr[row][rt].tt1;
        Tr[row][rt].t1=0;Tr[row][rt].tt1=false;
    }
}

void update1(int L,int R,int row,int x,int l,int r,int rt){
    if(L<=l&&r<=R){
        Tr[row][rt].sum+=(r-l+1)*x;
        Tr[row][rt].mina+=x;
        Tr[row][rt].maxa+=x;
        Tr[row][rt].t1+=x;
        Tr[row][rt].tt1=true;
        return ;
    }
    PushDown(row,rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update1(L,R,row,x,lson);
    if(R>m) update1(L,R,row,x,rson);
    PushUp(row,rt);
}

void update2(int L,int R,int row,int x,int l,int r,int rt){
    if(L<=l&&r<=R){
        Tr[row][rt].sum=(r-l+1)*x;
        Tr[row][rt].mina=x;
        Tr[row][rt].maxa=x;
        Tr[row][rt].t2=x;
        Tr[row][rt].tt2=true;
        Tr[row][rt].t1=0;
        Tr[row][rt].tt1=false;
        return ;
    }
    PushDown(row,rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update2(L,R,row,x,lson);
    if(R>m) update2(L,R,row,x,rson);
    PushUp(row,rt);
}

int query_sum(int L,int R,int row,int l,int r,int rt){
    if(L<=l&&r<=R){
        return Tr[row][rt].sum;
    }
    PushDown(row,rt,r-l+1);
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m) ret+=query_sum(L,R,row,lson);
    if(R>m) ret+=query_sum(L,R,row,rson);
    return ret;
}

int query_min(int L,int R,int row,int l,int r,int rt){
    if(L<=l&&r<=R){
        return Tr[row][rt].mina;
    }
    PushDown(row,rt,r-l+1);
    int m=(l+r)>>1;
    int ret=INF;
    if(L<=m) ret=min(ret,query_min(L,R,row,lson));
    if(R>m) ret=min(ret,query_min(L,R,row,rson));
    return ret;
}

int query_max(int L,int R,int row,int l,int r,int rt){
    if(L<=l&&r<=R){
        return Tr[row][rt].maxa;
    }
    PushDown(row,rt,r-l+1);
    int m=(l+r)>>1;
    int ret=-1;
    if(L<=m) ret=max(ret,query_max(L,R,row,lson));
    if(R>m) ret=max(ret,query_max(L,R,row,rson));
    return ret;
}

int main(){
    //ifstream cin("in.txt");
    int r,c,m;
    while(cin>>r>>c>>m){
        memset(Tr,0,sizeof(Tr));
        int op,x1,x2,y1,y2,v;
        while(m--){
            cin>>op;
            if(op==1){
                cin>>x1>>y1>>x2>>y2>>v;
                for(int i=x1;i<=x2;i++)
                    update1(y1,y2,i,v,1,c,1);
            }
            else if(op==2){
                cin>>x1>>y1>>x2>>y2>>v;
                for(int i=x1;i<=x2;i++)
                    update2(y1,y2,i,v,1,c,1);
            }
            else{
                cin>>x1>>y1>>x2>>y2;
                int sum=query_sum(y1,y2,x2,1,c,1);
                int ret1=query_min(y1,y2,x2,1,c,1);
                int ret2=query_max(y1,y2,x2,1,c,1);
                for(int i=x1;i<x2;i++){
                    sum+=query_sum(y1,y2,i,1,c,1);
                    ret1=min(ret1,query_min(y1,y2,i,1,c,1));
                    ret2=max(ret2,query_max(y1,y2,i,1,c,1));
                }
                cout<<sum<<" "<<ret1<<" "<<ret2<<endl;
            }
        }
    }
    return 0;
}
