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

const int maxn=210000;
const int maxm=2000010;
const int inf=1e9+7;

int t1[maxn],t2[maxn],c[maxn];

bool cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int str[],int sa[],int ran[],int height[],int n,int m){
    ++n;
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;++i) c[i]=0;
    for(i=0;i<n;++i) c[x[i]=str[i]]++;
    for(i=1;i<m;++i) c[i]+=c[i-1];
    for(i=n-1;i>=0;--i) sa[--c[x[i]]]=i;

    for(j=1;j<=n;j<<=1){
        p=0;
        for(i=n-j;i<n;++i) y[p++]=i;
        for(i=0;i<n;++i) if(sa[i]>=j) y[p++]=sa[i]-j;

        for(i=0;i<m;++i) c[i]=0;
        for(i=0;i<n;++i) c[x[y[i]]]++;
        for(i=1;i<m;++i) c[i]+=c[i-1];
        for(i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];

        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;++i)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;
    }
    int k=0;
    --n;
    for(i=0;i<=n;++i) ran[sa[i]]=i;
    for(i=0;i<n;++i){
        if(k) --k;
        j=sa[ran[i]-1];
        while(str[i+k]==str[j+k]) ++k;
        height[ran[i]]=k;
    }
}

int ran[maxn];
int height[maxn];
int RMQ[maxn];
int mm[maxn];

int best[25][maxn];

void initRMQ(int n){
    mm[0]=-1;
    for(int i=1;i<=n;++i)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];

    for(int i=1;i<=n;++i) best[0][i]=i;
    for(int i=1;i<=mm[n];++i)
        for(int j=1;j+(1<<i)-1<=n;++j){
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(RMQ[a]<RMQ[b]) best[i][j]=a;
            else best[i][j]=b;
        }
}

int askRMQ(int a,int b){
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}

char stmp[maxn];
char str[maxn];
int sstr[maxn];
int r[maxn];
int sa[maxn];
int maxL;

int find(char s[],int len){
    int l=1,r=maxL,L=maxL+1,R;
//    cout<<"s="<<" "<<s<<" "<<len<<endl;
    while(l<=r){
        int mid=(l+r)>>1;
//        cout<<l<<" "<<r<<" "<<str+sa[mid]<<endl;
        if(strcmp(s,str+sa[mid])<0){
            L=min(L,mid);r=mid-1;
        }
        else l=mid+1;
    }
//    cout<<s<<endl;
//    cout<<L<<" "<<str+sa[L]<<endl;

    for(int i=0;i<len;++i)
        if(s[i]!=str[sa[l]+i]) return 0;

    r=maxL;l=L+1;R=L;
//    cout<<"l="<<l<<" r="<<r<<endl;
//    cout<<"***"<<height[askRMQ(L+1,L+1)]<<endl;
//    cout<<"-----"<<endl;
    while(l<=r){
        int mid=(l+r)>>1;
//        cout<<l<<" "<<r<<" "<<mid<<endl;
        if(height[askRMQ(L+1,mid)]>=len){
            R=max(R,mid);l=mid+1;
        }
        else r=mid-1;
    }
//    cout<<L<<" "<<R<<endl;
//    cout<<"R="<<R<<" "<<str+sa[R]<<endl;
//    cout<<L<<" "<<R<<endl;
    return (R-L+1);
}

int solve(char *str){
    int len=strlen(str);

    int key=find(str,len);

//    cout<<"key="<<key<<endl;

    if(key<=0) return 0;
    int ans=0;

    for(int l=len-1;l>0;--l){
        if(find(str+l,len-l)==key){
            ans=l;
            break;
        }
    }
    return ans+1;
    int l=0,r=len-1;
//    while(l<=r){
//        int mid=(l+r+1)>>1;
////        cout<<l<<" "<<r<<" "<<mid<<endl;
//        if(find(str+mid,len-mid)==key){
//            ans=max(ans,mid);l=mid+1;
//        }
//        else r=mid-1;
//    }
//    return ans+1;
}

int main(){
//    ifstream cin("in.txt");
//    freopen("in.txt","r",stdin);

    int T,u,v,n,m,icase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);

        str[0]=0;maxL=0;
        for(int i=0;i<n;++i){
            scanf("%s",stmp);
            maxL+=strlen(stmp);
            strcat(str,stmp);
            str[maxL++]='#';
            str[maxL]=0;
        }

        for(int i=0;i<=maxL;++i)
            sstr[i]=str[i];

        da(sstr,sa,ran,height,maxL,128);

        for(int i=1;i<=maxL;++i)
            RMQ[i]=height[i];
        initRMQ(maxL);
//        cout<<"***"<<endl;
//        for(int i=0;i<=maxL;++i)
//            cout<<height[i]<<" ";
//        cout<<endl;

        printf("Case #%d:\n",++icase);
        while(m--){
            scanf("%s",stmp);
//            cout<<stmp<<endl;
            printf("%d\n",solve(stmp));
        }
    }
    return 0;
}
