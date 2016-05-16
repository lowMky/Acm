/*
ID: onlyazh1
LANG: C++
TASK: test
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e6+7;

const int inf = 1e9+7;

int p[maxn],a[maxn];
int pre[maxn],nex[maxn];
pair<int,int> c[maxn];
set<pair<int,int> > S;
int n,m;
int time(int x,int y){
    if(x==y) return inf;
    ll p1=p[x],p2=p[y];
    if(x>y) p2=(p2+a[y])%m;
    if(p1>p2) p2+=m;
    if(p2-p1<=a[x]) return 1;
    if(a[y]>=a[x]) return inf;
    int l=1,r=inf;
    while(l<r){
        int mid=(l+r)/2;
        if(p1+1ll*a[x]*mid>=p2+1ll*a[y]*(mid-1))
            r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>p[i]>>a[i];
        p[i]--;
        c[i].first=p[i];
        c[i].second=i;
    }
    sort(c,c+n);

    for(int i=0;i<n;i++){
        pre[c[i].second]=c[(i-1+n)%n].second;
        nex[c[i].second]=c[(i+1)%n].second;
    }

    for(int i=0;i<n;i++)
        S.insert(make_pair(time(i,nex[i]),i));

    while(!S.empty()){
        pair<int,int> now= *S.begin();
        if(now.first==inf) break;
        S.erase(now);
        int x=now.second;

        S.erase(make_pair(time(nex[x],nex[nex[x]]),nex[x]));
        S.erase(make_pair(time(pre[x],x),pre[x]));

        p[x]+=now.first;a[x]--;

        nex[x]=nex[nex[x]];
        pre[nex[x]]=x;

        S.insert(make_pair(time(pre[x],x),pre[x]));
        S.insert(make_pair(time(x,nex[x]),x));
    }

    cout<<(int)S.size()<<endl;
    for(auto s:S)
        cout<<s.second+1<<" ";
    cout<<endl;
    return 0;
}


