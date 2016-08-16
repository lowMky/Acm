#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
#include<cstring>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const double eps=1e-8;
const int maxn=210;
const int maxm=200010;
const int inf=1e9;
const ll MOD=2;


struct Node{
    int x,y,z;
    Node(){}
    Node(int _x,int _y,int _z){
        x=_x;y=_y;z=_z;
    }
}node[maxn];

int nt[maxn];

double dis(int a,int b){
    double x=(node[a].x-node[b].x)*(node[a].x-node[b].x);
    double y=(node[a].y-node[b].y)*(node[a].y-node[b].y);
    double z=(node[a].z-node[b].z)*(node[a].z-node[b].z);

    return x+y+z;
}

Node xmul(Node i,Node j,Node k){
    int z=(i.x-j.x)*(k.y-j.y)-(i.y-j.y)*(k.x-j.x);
    int y=(i.z-j.z)*(k.x-j.x)-(i.x-j.x)*(k.z-j.z);
    int x=(i.y-j.y)*(k.z-j.z)-(i.z-j.z)*(k.y-j.y);
    return Node(x,y,z);
}

Node xmul(int i,int j,int k){
    return xmul(node[i],node[j],node[k]);
}

bool ok(int a,int b,int c,int d){
    Node il=Node(node[a].x-node[d].x,node[a].y-node[d].y,node[a].z-node[d].z);
    Node s=xmul(a,b,c);
    return s.x*il.x+s.y*il.y+s.z*il.z;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,n,ans1,ans2,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].z);
        int cnt=0;
        ans1=0;ans2=0;
        for(int p=0;p<n;++p){
            for(int q=p+1;q<n;++q){
                double pq=dis(p,q);
                cnt=0;
                for(int i=0;i<n;++i){
                    if(i==p||i==q) continue;
                    if(fabs(dis(i,q)-dis(i,p))<eps)
                        nt[cnt++]=i;
                }

                for(int i=0;i<cnt;++i)
                    for(int j=i+1;j<cnt;++j){
                        if(fabs(dis(nt[i],p)-dis(nt[j],p))>eps)
                            continue;
                        if(ok(p,q,nt[i],nt[j])){
                            ++ans1;
                            if(fabs(pq-dis(nt[i],nt[j]))<eps&&fabs(pq-dis(nt[i],p))<eps)
                                ++ans2;
                        }
                    }

//                    double ip=dis(i,p);
//                    if(fabs(ip-dis(i,q))<eps){
//                        cnt=0;
//                        nt[cnt++]=i;
//                        for(int j=i+1;j<n;j++){
//                            if(j==p||j==q) continue;
//                            double jp=dis(j,p);
//                            if(fabs(jp-dis(i,q))<eps&&fabs(ip-jp)<eps)
//                                nt[cnt++]=j;
//                        }
//
//                        for(int g=0;g<cnt;++g){
//                            for(int f=g+1;f<cnt;++f){
//                                if(ok(p,q,nt[g],nt[f]))
//                                    continue;
//                                ++ans1;
//                                if((fabs(pq-dis(nt[f],nt[g]))<eps)&&(fabs(pq-ip)<eps))
//                                    ++ans2;
//                            }
//                        }
//                    }
//                }
            }
        }
//        cout<<ans1<<" "<<ans2<<endl;
        printf("Case #%d: %d\n",++icase,ans1/2-ans2/3);
    }
    return 0;
}
