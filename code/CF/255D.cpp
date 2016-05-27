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



ll n,x,y,c;

ll cal(ll mid){
    ll ret=1;
    bool f1,f2,f3,f4;
    f1=f2=f3=f4=false;
    ret+=min(mid,x-1);
    ret+=min(mid,n-x);
    ret+=min(mid,y-1);
    ret+=min(mid,n-y);
//    cout<<ret<<endl;
    ret+=2*(mid-1)*mid;
//    cout<<ret<<endl;
    if(mid>x-1+1){
        f1=true;
        ret-=(mid-x+1)*(mid-x);
    }
//    cout<<ret<<endl;
    if(mid>n-x+1){
        f2=true;
        ret-=(mid-n+x)*(mid-n+x-1);
    }
//    cout<<ret<<endl;
    if(mid>y-1+1){
        f3=true;
        ret-=(1+mid-y)*(mid-y);
    }
//    cout<<ret<<endl;
    if(mid>n-y+1){
        f4=true;
        ret-=(mid-n+y)*(mid-n+y-1);
    }
//    cout<<ret<<endl;
    if(f1){
        if(f3){
            ll t=(mid-x)+(mid-y)-mid+1;
            if(t>0)
                ret+=t*(t+1)/2;
//            cout<<"1 "<<ret<<endl;
        }
        if(f4){
            ll t=(mid-x)+(mid-n+y-1)-mid+1;
            if(t>0)
                ret+=t*(t+1)/2;
//            cout<<"2 "<<ret<<endl;
        }
    }

    if(f2){
        if(f3){
            ll t=(mid-n+x-1)+(mid-y)-mid+1;
            if(t>0)
                ret+=t*(t+1)/2;
//            cout<<"3 "<<ret<<endl;
        }
        if(f4){
            ll t=(mid-n+x-1)+(mid-n+y-1)-mid+1;
            if(t>0)
                ret+=t*(t+1)/2;
//            cout<<"4 "<<ret<<endl;
        }
    }
    return ret;
}

int main(){
//    ifstream cin("in.txt");

    cin>>n>>x>>y>>c;
//    cout<<cal(4)<<endl;
//    cout<<cal(3)<<endl;
    ll l=0,r=n*2;
    while(l<r){
        ll mid=(l+r)>>1;
        if(cal(mid)<c)
            l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}
