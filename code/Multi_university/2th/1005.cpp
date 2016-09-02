#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

const ll MOD=1e9+7;
const int maxn=1010;

map<double,int> M;

struct Point{
    int x,y;
    int cnt;
}P[maxn];


template<class T>
inline bool scan_d(T &ret){
    char c;int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}

bool cmp(Point A,Point B){
    if(A.x==B.x) return A.y<B.y;
    else return A.x<B.x;
}

ll poww[1010];
ll pp[1010];
int cc;double k,b;ll ans,cnt;
map<double,int>::iterator itt;
int T,i,j;

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    pp[0]=1;
    for(i=1;i<=1000;++i)
        pp[i]=(pp[i-1]*2)%MOD;
    for(i=1;i<=1000;++i)
        poww[i]=(pp[i]-1-i+MOD)%MOD;

    scan_d(T);
    while(T--){
        int n;scan_d(n);//scanf("%d",&n);

        for(int i=0;i<n;++i){
            scan_d(P[i].x);
            scan_d(P[i].y);
            P[i].cnt=0;
        }

        cc=0;
        sort(P,P+n,cmp);
        for(int i=0;i<n;++i){
            if(P[i].x==P[cc].x&&P[i].y==P[cc].y)
                P[cc].cnt++;
            else{
                P[++cc]=P[i];
                P[cc].cnt=1;
            }
        }


        ans=0;
        for(i=0;i<=cc;++i){
            M.clear();
            for(j=i+1;j<=cc;++j){
                if(P[i].x==P[j].x)
                    continue;
                k=(P[i].y-P[j].y)*1.0/(P[i].x-P[j].x);

                if(M.find(k)==M.end())
                    M[k]=P[j].cnt;
                else M[k]+=P[j].cnt;
            }
            for(itt=M.begin();itt!=M.end();++itt)
                ans=(ans+(pp[itt->second]-1)*(pp[P[i].cnt]-1))%MOD;;
        }


        cnt=P[0].cnt;
        for(i=1;i<=cc;++i){
            if(P[i].x==P[i-1].x)
                cnt+=P[i].cnt;
            else{
                ans+=poww[cnt];
                cnt=P[i].cnt;
            }
        }
        ans=(ans+poww[cnt])%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
