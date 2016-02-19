/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月09日 星期五 20时11分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    char str[1000000];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        map<ll,int> M;
        int cnt=0;
        ll t=1;
        ll num=0;
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]=='[')
                t*=2;
            else if(isdigit(str[i]))
                num=num*10+str[i]-'0';
            else
            {
                num*=t;
                if(str[i]==']')
                    t/=2;
                if(!isdigit(str[i-1]))
                    continue;
                if(M.find(num)==M.end())
                    M[num]=1;
                else
                    M[num]++;
                num=0;
                cnt++;
            }
        }
        int maxn=0;
        for(map<ll,int>::iterator it=M.begin();it!=M.end();it++)
            maxn=max(maxn,it->second);
        printf("%d\n",cnt-maxn);
    }
    return 0;
}
