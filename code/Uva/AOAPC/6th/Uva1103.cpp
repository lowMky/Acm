/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月01日 星期四 18时08分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;
int G[220][220];
char s[220];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char str[]={'W','A','K','J','S','D'};
vector<int> th;
int ho[40010];
int h,w,cnt;
void dfs(int y,int x)
{
    G[y][x]=cnt;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(G[ty][tx]==-1&&1<=tx&&tx<=w*4&&1<=ty&&ty<=h)
            dfs(ty,tx);
    }
}

void dfs2(int y,int x)
{
    G[y][x]=-1;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(0<=tx&&tx<=w*4+1&&0<=ty&&ty<=h+1)
        {
            if(G[ty][tx]>0)
            {
                int flag=0;
                for(int j=0;j<th.size();j++)
                    if(th[j]==G[ty][tx])
                    {
                        flag=1;
                        break;
                    }
                if(!flag)
                    th.push_back(G[ty][tx]);
            }
            else if(G[ty][tx]==0)
                dfs2(ty,tx);
        }    
    }
}

int main()
{
    int icase=0;
    while(cin>>h>>w)
    {
        if(h+w==0)
            break;
        cnt=0;
        memset(G,0,sizeof(G));
        memset(ho,0,sizeof(ho));
        for(int i=1;i<=h;i++)
        {
            cin>>s;
            for(int j=0;j<w;j++)
            {
                int d;
                if(isdigit(s[j]))
                    d=s[j]-'0';
                else
                    d=10+s[j]-'a';
                for(int k=4*j+4;k>4*j;k--,d/=2)
                    if(d%2)
                        G[i][k]=-1;
            } 
        }
        /* 
        for(int i=0;i<=h+1;i++)
        {
            for(int j=0;j<=w*4+1;j++)
                cout<<G[i][j]<<" ";
            cout<<endl;
        }
        */
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w*4;j++)
                if(G[i][j]==-1)
                {
                    ++cnt;
                    dfs(i,j);
                } 
        
        for(int i=0;i<=h+1;i++)
            for(int j=0;j<=w*4+1;j++)
            {
                if(G[i][j]==0)
                {
                    dfs2(i,j);
                    if(th.size()==1)
                        ho[th[0]]++;
                    th.clear();
                }   
            }
        
        char ans[40010];
        if(cnt==1)
            ho[1]--;
        for(int i=1;i<=cnt;i++)
            ans[i-1]=str[ho[i]];
        sort(ans,ans+cnt);
        icase++;
        cout<<"Case "<<icase<<": ";
        for(int i=0;i<cnt;i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
