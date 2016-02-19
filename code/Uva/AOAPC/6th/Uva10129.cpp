/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月01日 星期四 13时37分25秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int in[30];
int out[30];
char str[1100];
bool tag[2];
bool flag;
int par[30];
void init()
{
    tag[0]=tag[1]=flag=0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<26;i++)
        par[i]=i;
}

int find(int x)
{
    return par[x]==x?x:par[x]=find(par[x]);
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int a=str[0]-'a';
            int b=str[strlen(str)-1]-'a';
            in[a]++;
            out[b]++;
            a=find(a);
            b=find(b);
            if(a!=b)
                par[a] =b;
        }
        int x;
        for(int i=0;i<26;i++)
            if(in[i]||out[i])
            {
                x=i;
                break;
            }
        x=find(x);
        for(int i=0;i<26;i++)
            if((in[i]||out[i])&&find(i)!=x)
            {
                flag=1;
                break;
            }
        for(int i=0;i<26&&!flag;i++)
        {
            if(out[i]==in[i])
                continue;
            else if(out[i]==in[i]+1)
            {
                if(tag[0])
                    flag=1;
                else
                    tag[0]=true;
            }
            else if(out[i]+1==in[i])
            {
                if(tag[1])
                    flag=1;
                else
                    tag[1]=true;
            }
            else
                flag=1;
        }
        printf("%s\n",flag?"The door cannot be opened.":"Ordering is possible.");
    }
    return 0;
}
