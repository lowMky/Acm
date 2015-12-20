/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月12日 星期一 10时15分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;
vector<int> G[60];
int vis[60];
bool dfs(int u)
{
    vis[u]=-1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]==-1)
            return false;
        else if(!vis[v]&&!dfs(v))
            return false;
    }
    vis[u]=1;
    return true;
}
int main()
{
    int n;
    string str;
    while(cin>>n)
    {
        int flag=0;
        for(int i=0;i<60;i++)
        {
            G[i].clear();
            vis[i]=0;
        }
        while(n--)
        { 
            vector<int> V;
            cin>>str;
            for(int i=0;i<4;i++)
                if(str[i*2]!='0')
                {
                    int a=(str[i*2]-'A')*2;
                    if(str[i*2+1]=='+')
                        a++;
                    V.push_back(a);
                }
            for(int i=0;i<V.size();i++)
            {
                int a=V[i];
                for(int j=0;j<V.size();j++)
                {
                    if(i==j)
                        continue;
                    int b=V[j];
                    G[a].push_back(b^1);
                }
            }
        }
        for(int i=0;i<52;i++)
            if(!vis[i]&&!dfs(i))
            {
                cout<<"unbounded"<<endl;
                flag=1;
                break;
            }    
        if(!flag)
            cout<<"bounded"<<endl;
    }
    return 0;
}
