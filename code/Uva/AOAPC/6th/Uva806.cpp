/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月23日 星期五 16时09分11秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

char G[100][100];
vector <int> ans;
struct Node{
    int flag;
    Node *nw,*ne,*sw,*se;
    Node(){
        nw=ne=sw=se=NULL;
    }
};

void build_tree(Node *rt,int nw,int ne,int sw,int se){
    bool flag=false;
    for(int i=nw;i<=ne&&!flag;i++)
        for(int j=sw;j<=se;j++)
            if(G[i][j]!=G[nw][sw])
            {
                flag=true;
                break;
            }
    if(flag){
        rt->flag=0;
        rt->nw=new Node;
        build_tree(rt->nw,nw,(nw+ne)/2,sw,(sw+se)/2);
        rt->ne=new Node;
        build_tree(rt->ne,nw,(nw+ne)/2,(sw+se)/2+1,se);
        rt->sw=new Node;
        build_tree(rt->sw,(nw+ne)/2+1,ne,sw,(sw+se)/2);
        rt->se=new Node;
        build_tree(rt->se,(nw+ne)/2+1,ne,(sw+se)/2+1,se);
    }
    else{
        if(G[nw][sw]=='1')
            rt->flag=1;
        else
            rt->flag=-1;
    }
}

void find_black(Node *rt,int dep,int tot){
    if(rt->flag==-1)
        return;
    if(rt->flag==1){
        ans.push_back(tot);
    }
    else{
        find_black(rt->nw,dep*5,tot+1*dep);
        find_black(rt->ne,dep*5,tot+2*dep);
        find_black(rt->sw,dep*5,tot+3*dep);
        find_black(rt->se,dep*5,tot+4*dep);
    }
}

void build_tree2(int num,int nw,int ne,int sw,int se){
    if(num){
        switch(num%5)
        {
            case 1:
                build_tree2(num/5,nw,(nw+ne)/2,sw,(sw+se)/2);break;
            case 2:
                build_tree2(num/5,nw,(nw+ne)/2,(sw+se)/2+1,se);break;
            case 3:
                build_tree2(num/5,(nw+ne)/2+1,ne,sw,(sw+se)/2);break;
            case 4:
                build_tree2(num/5,(nw+ne)/2+1,ne,(sw+se)/2+1,se);break;
        } 
    }
    else{
        for(int i=nw;i<=ne;i++)
            for(int j=sw;j<=se;j++)
                G[i][j]='*';
    }
}
int main(){
    int n;
    int icase=0;
    while(scanf("%d",&n)&&n){
        memset(G,0,sizeof(G));
        ans.clear();
        if(icase)
            printf("\n");
        printf("Image %d\n",++icase);
        if(n>0){
            for(int i=0;i<n;i++)
                scanf("%s",G[i]);
            Node rt;
            build_tree(&rt,0,n-1,0,n-1);
            find_black(&rt,1,0);
            sort(ans.begin(),ans.end());
            for(int i=0,sz=ans.size();i<sz;i++)
            {
                printf("%d",ans[i]);
                if(i==sz-1||(i+1)%12==0)
                    printf("\n");
                else
                    printf(" ");
            }
            int sz=ans.size();
            printf("Total number of black nodes = %d\n", sz);  
        }
        else{
            n*=-1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    G[i][j]='.';
                G[i][n]=0;
            }
            int num;
            while(1){
                scanf("%d",&num);
                if(num==-1)
                    break;
                build_tree2(num,0,n-1,0,n-1);
            }   
            for(int i=0;i<n;i++)
                printf("%s\n",G[i]);
        }
    }
    return 0;
}
