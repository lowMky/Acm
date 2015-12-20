/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月19日 星期一 20时14分39秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct Poker{
    char suit;
    char rank;
};

stack<Poker> V[60];
vector<int> L;
bool scan()
{
    int cnt=0;
    Poker tmp;
    while(1)
    {
        cin>>tmp.rank;
        if(tmp.rank=='#')
            return false;
        cin>>tmp.suit;
        while(!V[cnt].empty())
            V[cnt].pop();
        V[cnt].push(tmp);
        L.push_back(cnt++);
        if(cnt==52)
            return true;
    }
}

bool judge(int loc,int tag)
{
    if(loc<tag)
        return false;
    Poker a=V[L[loc-tag]].top();
    Poker b=V[L[loc]].top();
    if(a.rank==b.rank||a.suit==b.suit)
    {
        V[L[loc-tag]].push(b);
        V[L[loc]].pop();
        if(V[L[loc]].empty())
            L.erase(L.begin()+loc);
        return true;
    }
    return false;
}
int main()
{
    while(scan())
    {
        while(1)
        {
            bool update=false;
            for(int i=0,sz=L.size();i<sz;i++)
                if(judge(i,3)||judge(i,1))
                {
                    update=true;
                    break;
                }
            if(!update)
                break;   
        }
        int sz=L.size();
        if(sz==1)    
            printf("%d pile remaining: ",sz);
        else
            printf("%d piles remaining: ",sz);
        for(int i=0;i<sz;i++)
        {
            int cnt=V[L[i]].size();
            printf("%d",cnt);
            if(i<sz-1)
                printf(" ");
            else
                printf("\n");
        }  
        L.clear();
    }
    return 0;
}
