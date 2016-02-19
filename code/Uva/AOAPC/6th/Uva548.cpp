/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月30日 星期三 13时40分19秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
struct Node{
    int val;
    Node *left,*right;
}root;
int loc[11000];
int pos[11000];
char s[20010];
int cnt;
int max_sum,min_val;
bool scan()
{
    memset(loc,0,sizeof(loc));
    memset(pos,0,sizeof(pos));
    memset(s,0,sizeof(s));
    int tmp,len=0;
    if(gets(s)==NULL)
        return false;
    cnt=0;
    while(*(s+len)!=0)
    {
        char stmp[100];
        sscanf(s+len,"%s",stmp);
        sscanf(stmp,"%d",&tmp);
        len+=(strlen(stmp)+1);
        loc[tmp]=cnt++;
    }   
    for(int i=0;i<cnt;i++)
        scanf("%d",&pos[i]);
    getchar();
    return true;
}

void build_tree()
{
    root.val=pos[cnt-1];
    root.left=root.right=NULL;
    for(int i=cnt-2;i>=0;i--)
    {
        Node *tmp=&root;
        int a=pos[i];
        while(1)
        {
            if(loc[a]>loc[(*tmp).val])
            {
                if((*tmp).right!=NULL)
                    tmp=(*tmp).right;
                else
                {
                    (*tmp).right=new Node;
                    tmp=(*tmp).right;
                    (*tmp).left=(*tmp).right=NULL;
                    (*tmp).val=a;
                    break;
                }    
            }
            else
            {
                if((*tmp).left!=NULL)
                    tmp=(*tmp).left;
                else
                {
                    (*tmp).left=new Node;
                    tmp=(*tmp).left;
                    (*tmp).left=(*tmp).right=NULL;
                    (*tmp).val=a;
                    break;   
                }
            }
        }
       // printf("%d\n",a);
    }
}

void dfs(Node *tmp,int sum)
{
    sum+=(*tmp).val;
    if((*tmp).left==NULL&&(*tmp).right==NULL)
    {
        if(max_sum>sum)
        {
            max_sum=sum;
            min_val=(*tmp).val;
        }
        if(max_sum==sum)
            min_val=min(min_val,(*tmp).val);
    }
    if((*tmp).left!=NULL)
        dfs((*tmp).left,sum);
    if((*tmp).right!=NULL)
        dfs((*tmp).right,sum);
}

void dfs2(Node *tmp)
{
    printf("%d\n",(*tmp).val);
    if(tmp->left)
        dfs2(tmp->left);
    if(tmp->right)
    dfs2(tmp->right);
}
int main()
{
    while(scan())
    {
        max_sum=INF;
        build_tree();
        //dfs2(&root);
        dfs(&root,0);
        printf("%d\n",min_val);
    }
    return 0;
}
