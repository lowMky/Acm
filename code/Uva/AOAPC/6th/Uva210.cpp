/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月02日 星期五 10时19分25秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

struct code{
    int op,var,val;
}op[10000][30];

int val[30];
int T[5];
int Q,n;
bool lock;
int tnow[10000];
deque<int> que;
queue<int> block;
int rear,front,brear,bfront;
int init()
{
    lock=false;
    memset(val,0,sizeof(val));
    memset(op,0,sizeof(op));
    memset(tnow,0,sizeof(tnow));
}
void scan()
{ 
    cin>>n;
    for(int i=0;i<5;i++)
        cin>>T[i];
    cin>>Q; 
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        int val;
        string s;
        while(1)
        {
            cin>>s;
            if(s.length()==1)
            {
                op[i][cnt].op=0;
                op[i][cnt].var=s[0]-'a';
                cin>>s;
                cin>>val;
                op[i][cnt].val=val;
            }
            else if(s.length()==5)
            {
                op[i][cnt].op=1;
                cin>>s;
                op[i][cnt].var=s[0]-'a';
            }
            else if(s.length()==4)
                op[i][cnt].op=2;
            else if(s.length()==6)
                op[i][cnt].op=3;
            else if(s.length()==3)
            {
                op[i][cnt].op=4;
                break;
            }
            cnt++;
        }
    }
}

bool done(int id)
{
    switch(op[id][tnow[id]].op)
    {
        case 0:
            val[op[id][tnow[id]].var]=op[id][tnow[id]].val;break;
        case 1:
            printf("%d: %d\n",id+1,val[op[id][tnow[id]].var]);break;
        case 2:
        {
            if(!lock)
                lock=true;
            else
            {
                block.push(id);
                return false;
            }
            break;
        }
        case 3:
        {
            lock=false;
            if(!block.empty())
            {
                int u=block.front();
                block.pop();
                que.push_front(u);
            }
            break;
        }
        case 4:
            return false;
    }
    tnow[id]++;
    return true;
}
void solve()
{
    for(int i=0;i<n;i++)
        que.push_back(i);
    while(!que.empty())
    {
        int flag=0;
        int id=que.front();
        que.pop_front();
        for(int i=0;i<Q;)
        {
            i+=T[op[id][tnow[id]].op];
            if(!done(id))
            {
                flag=1;
                 break;
            }
        }
        if(!flag)
            que.push_back(id);
        if(que.empty())
            while(!block.empty())
            {
                int u=block.front();
                block.pop();
                que.push_front(u);
            }
    }
}

int main()
{
    int icase;
    cin>>icase;
    while(icase--)
    {
        init();
        scan();
        solve();
        if(icase)
            cout<<endl;
    }
    return 0;
}
