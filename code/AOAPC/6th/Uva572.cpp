/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月01日 星期四 11时50分16秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool vis[120][120];
char Ma[120][120];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int n,m;
void dfs(int y,int x)
{
    vis[y][x]=true;
    for(int i=0;i<8;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(0<=ty&&ty<n&&0<=tx&&tx<m&&!vis[ty][tx]&&Ma[ty][tx]=='@')
            dfs(ty,tx);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i)
            scanf("%s",Ma[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j]&&Ma[i][j]=='@')
                {
                    cnt++;
                    dfs(i,j);
                }
        printf("%d\n",cnt);
    }
    return 0;
}
