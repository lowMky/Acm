/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 20时36分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Node{
    int num;
    Node *left,*right;
}root;

int flag=0;
vector<int> ans;
char s[1100];
void add(int num,char *s)
{
    Node *roo=&root;
    while(1)
    {
        if(*s=='L')
        {
            if((*roo).left==NULL)
            {
                (*roo).left=new Node;
                roo=(*roo).left;
                (*roo).num=0;
                (*roo).left=(*roo).right=NULL;
            }
            else
                roo=(*roo).left;
            s++;
        }
        else if(*s=='R')
        {
            if((*roo).right==NULL)
            {
                (*roo).right=new Node;
                roo=(*roo).right;
                (*roo).num=0;
                (*roo).left=(*roo).right=NULL;
            }
            else
                roo=(*roo).right;
            s++;
        }
        else if(*s==')')
        {
            if((*roo).num!=0)
                flag=1;
            else
                (*roo).num=num;
            break;
        }
    }
}

bool input()
{
    ans.clear();
    flag=0;
    root.num=0;
    root.left=root.right=NULL;
    for(;;)
    {
        if(scanf("%s",s)!=1)
            return false;
        if(!strcmp(s,"()"))
            break;
        int v;
        sscanf(&s[1],"%d",&v);
        add(v,strchr(s,',')+1);
    }
    return true;
}

void bfs()
{
    queue<Node> que;
    que.push(root);
    while(!que.empty())
    {
        Node tmp=que.front();
        que.pop();
        if(tmp.num==0)
        {
            flag=1;
            break;
        }
        ans.push_back(tmp.num);
        if(tmp.left!=NULL)
            que.push(*tmp.left);
        if(tmp.right!=NULL)
            que.push(*tmp.right);
    }
}

int main()
{
    while(input())
    {
        bfs();  
        if(flag)
            printf("not complete\n");
        else
        {
            for(int i=0;i<ans.size()-1;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[ans.size()-1]);
        }
    }
    return 0;
}
