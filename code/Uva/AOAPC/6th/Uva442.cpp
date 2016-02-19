/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 12时39分40秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cctype>
#include<stack>
#include<algorithm>
using namespace std;
struct Matrix{
    int x,y;
}Ma[30];
int main()
{
    int n;
    char ch;
    string str;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            cin>>Ma[ch-'A'].x>>Ma[ch-'A'].y;
        }
        while(cin>>str)
        {
            int flag=1; int ans=0;
            stack<Matrix> S;           
            int len=str.length();
            for(int i=0;i<len;i++)
            {
                if(str[i]=='(')
                    continue;
                if(isalpha(str[i]))
                    S.push(Ma[str[i]-'A']); 
                else
                {
                    Matrix a=S.top();S.pop();
                    Matrix b=S.top();S.pop();
                    if(a.x!=b.y)
                    {
                        flag=0;
                        break;
                    }
                    ans+=b.x*b.y*a.y;
                    b.y=a.y;
                    S.push(b);
                }
            }
            if(flag)
                cout << ans << endl;
            else
                cout<<"error"<< endl;
        }
    }
    return 0;
}
