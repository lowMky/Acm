/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月30日 星期三 20时55分46秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
struct Node{
    bool black;
    Node *ul,*ur,*dl,*dr;
    Node(){
        black=false;
    }
}*root;
Node *newnode()
{
    Node *tmp=new Node;
    tmp->ul=NULL;
    tmp->ur=NULL;
    tmp->dl=NULL;
    tmp->dr=NULL;
    return tmp;
}

void scan(Node *root)
{
    char ch;
    cin>>ch;
    if(ch=='e')
        return;
    if(ch=='f')
    {
        root->black=true;
        return;
    }
    else
    {
        if(root->ul==NULL)
            root->ul=newnode();
        scan(root->ul);
        if(root->ur==NULL)
            root->ur=newnode();
        scan(root->ur);
        if(root->dl==NULL)
            root->dl=newnode();
        scan(root->dl);
        if(root->dr==NULL)
            root->dr=newnode();
        scan(root->dr);
    }
}

int dfs(Node *root,int dep)
{
    int res=0;
    if(root->black)
        return dep;
    else
    {
        if(root->ul==NULL)
            return 0;
        res+=dfs(root->ul,dep/4);
        res+=dfs(root->ur,dep/4);
        res+=dfs(root->dl,dep/4);
        res+=dfs(root->dr,dep/4);
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        root=newnode();
        scan(root);
        scan(root);
        printf("There are %d black pixels.\n",dfs(root,1024));
    }
    return 0;
}
