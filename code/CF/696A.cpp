#include<bits/stdc++.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll inf=1e18;
const int MOD=1e9;

struct Node{
    ll val;
    int l,r;
}tr[5001000];

int U[800];int V[800];
int limu,limv,cnt;

void cha(ll u,int &lim,int s[]){
    lim=0;
    while(u){
        s[lim++]=u%2;
        u>>=1;
    }
    for(int p=0,q=lim-1;p<q;p++,q--)
        swap(s[p],s[q]);
}

int sam(int U[],int V[],int lim){
    for(int i=0;i<lim;++i)
        if(U[i]!=V[i]) return i;
    return lim;
}

void update(int rt,int idx,int lim,ll w,int sam,int U[],int V[]){
    if(idx>=lim) return ;
    if(!U[idx]){
        if(!tr[rt].l)
            tr[rt].l=++cnt;
        if(idx>=sam&&idx<lim) tr[tr[rt].l].val+=w;
        update(tr[rt].l,idx+1,lim,w,sam,U,V);
    }
    else{
        if(!tr[rt].r)
            tr[rt].r=++cnt;
        if(idx>=sam&&idx<lim) tr[tr[rt].r].val+=w;
        update(tr[rt].r,idx+1,lim,w,sam,U,V);
    }
}

ll query(int rt,int idx,int lim,int U[]){
    if(idx>=lim)
        return tr[rt].val;
    else{
        if(U[idx]){
            return (idx==1?0:tr[rt].val)+(tr[rt].r?query(tr[rt].r,idx+1,lim,U):0);
        }
        else{
            return (idx==1?0:tr[rt].val)+(tr[rt].l?query(tr[rt].l,idx+1,lim,U):0);
        }
    }
}

int main(){
//    ifstream cin("in.txt");

    memset(tr,0,sizeof(tr));
    int Q;cin>>Q;cnt=0;
    limu=limv=0;
    ll u,v,w;int flag,ss;
    for(int i=0;i<Q;++i){
        cin>>flag;
        cin>>u>>v;
        cha(u,limu,U);cha(v,limv,V);

//        cout<<u<<" "<<v<<endl;
//
//        for(int i=0;i<limu;++i)
//            cout<<U[i];
//        cout<<endl;
//        for(int i=0;i<limv;++i)
//            cout<<V[i];
//        cout<<endl;

        ss=sam(U,V,min(limu,limv));
        if(flag==1){
//            cout<<u<<" "<<v<<endl;
            cin>>w;
//            cout<<"Tr="<<tr[0].val<<endl;
            update(0,1,limu,w,ss,U,V);
//            cout<<"Tr="<<tr[0].val<<endl;
            update(0,1,limv,w,ss,V,U);
//            cout<<"Tr="<<tr[0].val<<endl;
        }
        else{
//            cout<<query(0,1,limu,U)<<" "<<query(0,1,limv,V)<<" "<<query(0,1,ss,U)<<endl;
            cout<<query(0,1,limu,U)+query(0,1,limv,V)-2*query(0,1,ss,U)<<endl;
        }
    }
    return 0;
}


