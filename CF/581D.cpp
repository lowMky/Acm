/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月22日 星期二 19时55分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
struct tar{
    int x,y;
    char ch;
}tar[3];

bool judge2(int a,int b,int c)
{
    if(tar[a].x==tar[b].x&&tar[b].x==tar[c].x&&tar[a].y+tar[b].y+tar[c].y==tar[a].x)
        return true;
    swap(tar[b].x,tar[b].y);
    if(tar[a].x==tar[b].x&&tar[b].x==tar[c].x&&tar[a].y+tar[b].y+tar[c].y==tar[a].x)
        return true;
    swap(tar[c].x,tar[c].y);
    if(tar[a].x==tar[b].x&&tar[b].x==tar[c].x&&tar[a].y+tar[b].y+tar[c].y==tar[a].x)
        return true;
    swap(tar[b].x,tar[b].y);
    if(tar[a].x==tar[b].x&&tar[b].x==tar[c].x&&tar[a].y+tar[b].y+tar[c].y==tar[a].x)
        return true;
    return false;
}

void print2(int a,int b,int c)
{
    printf("%d\n",tar[a].x);
    for(int i=0;i<tar[a].y;i++)
    {
        for(int j=0;j<tar[a].x;j++)
            printf("%c",tar[a].ch);
        puts("");
    }   
    for(int i=0;i<tar[b].y;i++)
    {
        for(int j=0;j<tar[b].x;j++)
            printf("%c",tar[b].ch);
        puts("");
    }   
    for(int i=0;i<tar[c].y;i++)
    {
        for(int j=0;j<tar[c].x;j++)
            printf("%c",tar[c].ch);
        puts("");
    }   

}
bool judge(int a,int b,int c)
{
    if(tar[a].x==tar[b].x+tar[c].x&&tar[a].y+tar[b].y==tar[a].x&&tar[b].y==tar[c].y)
        return true;
    swap(tar[b].x,tar[b].y);
    if(tar[a].x==tar[b].x+tar[c].x&&tar[a].y+tar[b].y==tar[a].x&&tar[b].y==tar[c].y)
        return true;
    swap(tar[c].x,tar[c].y);
    if(tar[a].x==tar[b].x+tar[c].x&&tar[a].y+tar[b].y==tar[a].x&&tar[b].y==tar[c].y)
        return true;
    swap(tar[b].x,tar[b].y);
    if(tar[a].x==tar[b].x+tar[c].x&&tar[a].y+tar[b].y==tar[a].x&&tar[b].y==tar[c].y)
        return true;
    return false;
}
void print(int a,int b,int c)
{
    printf("%d\n",tar[a].x);
    for(int i=0;i<tar[a].y;i++)
    {
        for(int j=0;j<tar[a].x;j++)
            printf("%c",tar[a].ch);
        puts("");
    }
    for(int i=0;i<tar[b].y;i++)
    {   for(int j=0;j<tar[b].x+tar[c].x;j++)
        {
            if(j<tar[b].x)
                printf("%c",tar[b].ch);
            else
                printf("%c",tar[c].ch);
        }
        puts("");
    }
}
int main()
{
    scanf("%d%d",&tar[0].x,&tar[0].y);
    tar[0].ch='A';
    scanf("%d%d",&tar[1].x,&tar[1].y);
    tar[1].ch='B';
    scanf("%d%d",&tar[2].x,&tar[2].y);
    tar[2].ch='C';
    int flag=0;
    if(!flag&&judge2(0,1,2))
    {
        flag=1;
        print2(0,1,2);
    }
    swap(tar[0].x,tar[0].y);
    if(!flag&&judge2(0,1,2))
    {
        flag=1;
        print2(0,1,2);
    }
    if(judge(0,1,2))
    {
        flag=1;
        print(0,1,2);
    }
    swap(tar[0].x,tar[0].y);
    if(!flag&&judge(0,1,2))
    {
        flag=1; 
        print(0,1,2); 
    }
    if(!flag&&judge(1,0,2))
    {
        flag=1;
        print(1,0,2);
    }
    swap(tar[1].x,tar[1].y);
    if(!flag&&judge(1,0,2))
    {
        flag=1;
        print(1,0,2);
    }
    if(!flag&&judge(2,0,1))
    {
        flag=1;
        print(2,0,1);    
    }
    swap(tar[2].x,tar[2].y);
    if(!flag&&judge(2,0,1))
    {
        flag=1;
        print(2,0,1);
    }
    if(!flag)
        printf("-1\n");
    return 0;
}
