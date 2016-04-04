/*
ID: onlyazh1
LANG: C++
TASK: RevolC FaeLoN
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
const int maxn=200100;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
struct Node{
    int mina,maxa,cnt,par;
}s[100100];
struct Point{
    int x,y;
}P[100100];

int id[maxn];
int M[maxn*10];
int sumc[maxn<<2];
int sums[maxn<<2];
int lazc[maxn<<2];
int lazs[maxn<<2];
int city,state,ct,n;

int find(int x){
    return s[x].par=(s[x].par==x?x:find(s[x].par));
}

void unio(int u,int v){
    s[v].par=u;
    s[u].mina=min(s[u].mina,s[v].mina);
    s[u].maxa=max(s[u].maxa,s[v].maxa);
    s[u].cnt+=s[v].cnt;
}

void PushDown(int rt){
    if(lazs[rt]){
        sums[rt<<1]+=lazs[rt];
        sums[rt<<1|1]+=lazs[rt];
        lazs[rt<<1]+=lazs[rt];
        lazs[rt<<1|1]+=lazs[rt];
        lazs[rt]=0;
    }
    if(lazc[rt]){
        sumc[rt<<1]+=lazc[rt];
        sumc[rt<<1|1]+=lazc[rt];
        lazc[rt<<1]+=lazc[rt];
        lazc[rt<<1|1]+=lazc[rt];
        lazc[rt]=0;
    }
}

void update(int L,int R,int s,int c,int l,int r,int rt){
    if(L<=l&&r<=R){
        lazs[rt]+=s;sums[rt]+=s;
        lazc[rt]+=c;sumc[rt]+=c;
        return ;
    }
    PushDown(rt);
    int m=(r+l)>>1;
    if(L<=m) update(L,R,s,c,lson);
    if(R>m) update(L,R,s,c,rson);
}

void query(int x,int l,int r,int rt){
    if(l==r){
        city=sumc[rt];
        state=sums[rt];
        return ;
    }
    PushDown(rt);
    int m=(r+l)>>1;
    if(x<=m) query(x,lson);
    else query(x,rson);
}

void build(int l,int r,int rt){
    lazs[rt]=lazc[rt]=sums[rt]=sumc[rt]=0;
    if(l==r) return ;
    int m=(r+l)>>1;
    build(lson);build(rson);
}

void init(){
    build(0,ct*2,1);
    for(int i=0;i<n;i++){
        s[i].par=i;s[i].cnt=1;
        s[i].mina=s[i].maxa=P[i].y;
        update(P[i].y,P[i].y,1,1,0,ct*2,1);
    }
}

int bin(int x){
    x*=2;
    int l=0,r=ct;
    while(l<r){
        int mid=(r+l)>>1;
        if(x<id[mid]) r=mid;
        else l=mid+1;
    }
    return id[l]==x?2*l:2*l-1;
}
int main(){
    //ifstream cin("in.txt");
    int T;cin>>T;
    while(T--){
        cin>>n;
        int u,v;string tmps;double x;
        for(int i=0;i<n;i++){
            cin>>P[i].x>>P[i].y;
            id[i]=P[i].y*2;
        }
        id[n]=0,id[n+1]=2000001;
        sort(id,id+n+2);
        ct=0;M[id[0]]=0;
        for(int i=1;i<n+2;i++)
            if(id[i]!=id[i-1]){
                id[++ct]=id[i];
                M[id[i]]=ct;
            }
        for(int i=0;i<n;i++)
            P[i].y=M[P[i].y*2]*2;
        init();
        cin>>n;
        while(n--){
            cin>>tmps;
            if(tmps=="road"){
                cin>>u>>v;
                u=find(u);v=find(v);
                if(u==v) continue;
                update(s[u].mina,s[u].maxa,-1,-s[u].cnt,0,ct*2,1);
                update(s[v].mina,s[v].maxa,-1,-s[v].cnt,0,ct*2,1);
                unio(u,v);
                update(s[u].mina,s[u].maxa,1,s[u].cnt,0,ct*2,1);
            }
            else{
                cin>>x;int d=bin(int(x));
                query(d,0,ct*2,1);
                cout<<state<<" "<<city<<endl;
            }
        }
    }
    return 0;
}
