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
const int maxn=200100;
const double PI=acos(-1);
struct Node{
    int x,h;
    int tag;
    bool operator < (const Node &A) const{
        return x<A.x;
    }
}node[maxn];
pair<double,double> ans[maxn];
int n,q;

double cmp(int a,int b){
    return fabs((node[a].h-node[b].h)*1.0/(node[a].x-node[b].x));
}

stack<int> S;
void solve(bool tt){
    while(!S.empty())
        S.pop();
    for(int i=0;i<n+q;++i){
        if(S.empty()){
            S.push(i);
            continue;
        }
        else{
            while(S.size()>=1){
                int t=S.top();
//                cout<<"***"<<i<<endl;
                S.pop();
//                cout<<node[t].h<<" "<<node[i].h<<endl;
                if(node[t].h<=node[i].h)
                    continue;
                if(S.empty()){
                    S.push(t);
                    break;
                }
                double k1=cmp(S.top(),t);
                double k2=cmp(t,i);
//                cout<<k1<<" "<<k2<<endl;
                if(k1<k2){
                    S.push(t);break;
                }
//                cout<<"S="<<S.size()<<endl;
            }
            if(node[i].tag!=-1){
                int t=S.top();
//                cout<<"t="<<t<<endl;
//                cout<<node[t].x<<" "<<node[t].h<<endl;
//                cout<<node[i].x<<" "<<node[i].h<<endl;
//                cout<<cmp(t,i)<<endl;
                if(tt) ans[node[i].tag].first=atan(cmp(t,i))*180/PI;
                else ans[node[i].tag].second=atan(cmp(t,i))*180/PI;
//                cout<<ans[node[i].tag].first<<endl;
                //cout<<"i="<<i<<" ndoe[i].tag="<<node[i].tag<<endl;
            }
//            cout<<i<<" "<<S.size()<<endl;
            S.push(i);
        }
    }

}


int main(){
//    freopen("in.txt","r",stdin);
    int T,icase=0;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&node[i].x,&node[i].h);
            node[i].tag=-1;
        }
        scanf("%d",&q);
        for(int i=0;i<q;++i){
            scanf("%d",&node[i+n].x);
            node[i+n].h=0;
            node[i+n].tag=i;
        }
        sort(node,node+n+q);
        solve(true);
        for(int a=0,b=n+q-1;a<b;++a,--b)
            swap(node[a],node[b]);
        solve(false);
        printf("Case #%d:\n",++icase);
        for(int i=0;i<q;i++){
            printf("%.5f\n",180-ans[i].first-ans[i].second);
        }
    }
    return 0;
}
