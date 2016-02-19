/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 14时33分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char s[110000];
int nex[110000];

int main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        int len=strlen(s+1);
        int cur=0;
        int last=0;
        nex[0]=0;
        for(int i=1;i<=len;i++)
        {
            if(s[i]=='[')
                cur=0;
            else if(s[i]==']')
                cur=last;
            else
            {
                nex[i]=nex[cur];
                nex[cur]=i;
                if(cur==last)
                    last=i;
                cur=i;
            }
        }
        for(int i=nex[0];i!=0;i=nex[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
