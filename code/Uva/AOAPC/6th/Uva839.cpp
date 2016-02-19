/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月30日 星期三 19时43分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;

bool solve(int &w)
{
    int l1,l2,w1,w2;
    bool b1=true,b2=true;
    scanf("%d%d%d%d",&w1,&l1,&w2,&l2);
    if(!w1)
        b1=solve(w1);
    if(!w2)
        b2=solve(w2);
    w=w1+w2;
    return b1&&b2&&w1*l1==w2*l2;
}
int main()
{
    int T,W;
    scanf("%d",&T);
    while(T--)
    {
        printf("%s\n",solve(W)?"YES":"NO");
        if(T)
            puts("");
    }
    return 0;
}
