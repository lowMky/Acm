/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月02日 星期五 14时54分16秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;

struct Node{
    int x,y,dep;
};
int dx[]={-2,-1,1,2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool vis[10][10];
Node ss,ee;

bool judge(Node a)
{
    if(0<a.x&&a.x<=8&&0<a.y&&a.y<=8&&!vis[a.y][a.x])
        return true;
    return false;
}
int bfs()
{
    Node tmp,tnow;
    queue<Node> que;
    que.push(ss);
    vis[ss.y][ss.x]=true;
    while(!que.empty())
    {
        tnow=que.front();
        que.pop();
        if(tnow.y==ee.y&&tnow.x==ee.x)
            return tnow.dep;
        for(int i=0;i<8;i++)
        {
            tmp.x=tnow.x+dx[i];
            tmp.y=tnow.y+dy[i];
            tmp.dep=tnow.dep+1;
            if(judge(tmp))
            {
                que.push(tmp);
                vis[tmp.y][tmp.x]=true;
            } 
        }
    }
    return -1;
}
int main()
{
    string s,e;
    while(cin>>s)
    {
        memset(vis,0,sizeof(vis));
        cin>>e;
        ss.x=s[1]-'0';
        ss.y=s[0]-'a'+1;
        ee.x=e[1]-'0';
        ee.y=e[0]-'a'+1;
        cout<<"To get from "<<s<<" to "<<e<<" takes "<<bfs()<<" knight moves."<<endl;
    }
    return 0;
}
