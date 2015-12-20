/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 14时56分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;
typedef long long ll;
int Right[110000];
int Left[110000];

void link(int L,int R)
{
    Right[L]=R;
    Left[R]=L;
}
int main()
{
    int n,m,icase=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y;
        int op=0,tag=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            Left[i]=i-1;
            Right[i]=(i+1)%(n+1);
        }
        
        for(int i=0;i<m;i++)
        {
            scanf("%d",&op);
            if(op==4)
            {
                tag^=1;
                continue;
            }
            scanf("%d%d",&x,&y);
            if(op==3&&Right[y]==x) swap(x,y);
            if(op!=3&&tag) op=3-op;
            if(op==1&&x==Left[y]) continue;
            if(op==2&&x==Right[y]) continue;
            int lx=Left[x],rx=Right[x],ly=Left[y],ry=Right[y];
            if(op==1)
            {
                link(lx,rx);
                link(ly,x);
                link(x,y);
            }
            if(op==2)
            {
                link(lx,rx);
                link(y,x);
                link(x,ry);
            }
            if(op==3)
            {
                if(Right[x]==y)
                {
                    link(lx,y);
                    link(y,x);
                    link(x,ry);
                }
                else
                {
                    link(lx,y);
                    link(y,rx);
                    link(ly,x);
                    link(x,ry);
                }   
            }
        }
        int s;
        if(tag)
        {
            for(int i=1;i<=n;i++)
                if(Right[i]==0)
                {
                    s=i;
                    break;
                }
            for(int cnt=0;cnt<n;cnt++,s=Left[s])
                if(cnt%2==0)
                    ans+=s;
        }
        else
        {
            for(int i=1;i<=n;i++)
                if(Left[i]==0)
                {
                    s=i;
                    break;
                }
            for(int cnt=0;cnt<n;cnt++,s=Right[s])
                if(cnt%2==0)
                    ans+=s;
        }
        printf("Case %d: %lld\n",++icase,ans);
    }
    return 0;
}
