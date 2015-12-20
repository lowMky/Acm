/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 19时43分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int d,cnt;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int ans=1;
            scanf("%d%d",&d,&cnt);
            for(int i=0;i<d-1;i++)
            {
                if(cnt%2)
                {
                    ans=ans*2;
                    cnt=(cnt+1)/2;
                }
                else
                {
                    ans=ans*2+1;
                    cnt/=2;
                }    
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
