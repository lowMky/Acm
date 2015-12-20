/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月30日 星期三 20时16分10秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int ans[201000];
int minn,maxn;
void scan(int loc)
{
    int tmp;
    scanf("%d",&tmp);
    if(tmp==-1)
        return;
    minn=min(minn,loc);
    maxn=max(maxn,loc);
    ans[loc]+=tmp;
    scan(loc-1);
    scan(loc+1);
}
int main()
{
    int icase=0;
    while(1)
    {
        minn=100001;
        maxn=100000;
        scan(100000);
        if(minn==100001)
            break;
        printf("Case %d:\n",++icase);
        for(int i=minn;i<=maxn;i++)
        {
            printf("%d",ans[i]);
            if(i!=maxn)
                printf(" ");
            ans[i]=0;
        }  
        printf("\n\n");
    }
    return 0;
}
