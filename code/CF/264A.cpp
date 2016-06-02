#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

typedef long long ll;
const int maxn=1000100;
const ll MOD=1e9+7;

char s[maxn];
int rt,cnt;
struct Tree{
    int l,r;
    int idx;
}Tr[maxn];

void insert(int & rt,int val,bool tag){
    Tr[rt].idx=val;
    if(tag){
        Tr[rt].l=++cnt;
        rt=cnt;
    }
    else{
        Tr[rt].r=++cnt;
        rt=cnt;
    }
}

void print(int rt){
    if(rt==cnt) return ;
    if(Tr[rt].l)
        print(Tr[rt].l);
    printf("%d\n",Tr[rt].idx+1);
    if(Tr[rt].r)
        print(Tr[rt].r);
}

int main(){
    scanf("%s",s);
    rt=cnt=0;
    for(int i=0,len=strlen(s);i<len;++i)
        insert(rt,i,s[i]=='l');
    print(0);
    return 0;
}
