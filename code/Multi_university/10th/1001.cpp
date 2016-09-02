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

const int maxn=100100;
const int maxm=2000010;
const int inf=1e9+7;

ll num[maxn];

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,n,m,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%lld",&num[i]);
        int l1,r1,l2,r2;
        while(m--){
            scanf("%d%d",&l1,&r1);
            scanf("%d%d",&l2,&r2);
            if(l1>l2){
                swap(l1,l2);swap(r1,r2);
            }

            if(r1<l2){
                int len11=r1-l1+1;
                int len22=r2-l2+1;
                int tot=len11+len22;
                if(tot%2){
                    int idx=tot/2+1;
                    if(idx<=len11)
                        printf("%.1f\n",num[l1+idx-1]*1.0);
                    else
                        printf("%.1f\n",num[l2+(idx-len11)-1]*1.0);
                }
                else{
                    int idx=tot/2;
                    double sum=0;
                    if(idx<len11)
                        sum=num[l1+idx-1]+num[l1+idx];
                    else if(idx==len11)
                        sum=num[r1]+num[l2];
                    else sum=num[l2+idx-len11-1]+num[l2+idx-len11];
                    printf("%.1f\n",sum/2);
                }
            }
            else if(r1<r2){
                int len11=(l2-l1);
                int len33=(r2-r1);
                int len22=(r1-l2+1)*2;
                int tot=len11+len22+len33;
                if(tot%2){
                    int idx=tot/2+1;
                    if(idx<=len11)
                        printf("%.1f\n",num[l1+idx-1]*1.0);
                    else if(idx<=len11+len22)
                        printf("%.1f\n",num[l1+len11-1+(idx-len11+1)/2]*1.0);
                    else printf("%.1f\n",num[l1+idx-len22/2-1]*1.0);
                }
                else{
                    int idx=tot/2;
                    double sum=0;
                    if(idx<=len11)
                        sum=num[l1+idx-1]+num[l1+idx];
                    else if(idx<=len11+len22)
                        sum=num[l1+len11+(idx-len11+1)/2-1]+num[l1+len11+(idx-len11+2)/2-1];
                    else
                        sum=num[l1+idx-len22/2-1]+num[l1+idx-len22/2];
                    printf("%.1f\n",sum/2);
                }
            }
            else{
                int len11=(l2-l1);
                int len33=(r1-r2);
                int len22=(r2-l2+1)*2;
//                cout<<len11<<" "<<len22<<" "<<len33<<endl;
                int tot=len11+len33+len22;
                if(tot%2){
                    int idx=tot/2+1;
                    if(idx<=len11)
                        printf("%.1f\n",num[l1+idx-1]*1.0);
                    else if(idx<=len11+len22)
                        printf("%.1f\n",num[l1+len11+(idx-len11+1)/2-1]*1.0);
                    else printf("%.1f\n",num[l1+idx-len22/2-1]*1.0);

                }
                else{
                    int idx=tot/2;
                    double sum=0;
                    if(idx<=len11)
                        sum=num[l1+idx-1]+num[l1+idx];
                    else if(idx<=len11+len22){
                        sum=num[l1+len11+(idx-len11+1)/2-1]+num[l1+len11+(idx-len11+2)/2-1];
//                        cout<<idx<<" "<<len11<<endl;
                    }
                    else
                        sum=num[l1+idx-len22/2-1]+num[l1+idx-len22/2];
                    printf("%.1f\n",sum/2);
                }
            }
        }
    }
    return 0;
}
