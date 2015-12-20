/*************************************************************************
	> File Name: acm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月28日 星期三 13时59分23秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n;
bool vis[10];

bool judge(int x){
    if(x%n!=0)
        return false;
    int m=x/n;
    for(int i=0;i<5;i++,x/=10,m/=10){
        if(vis[m%10])
            return false;
        else
            vis[m%10]=true;
        if(vis[x%10])
            return false;
        else
            vis[x%10]=true;
    }
    for(int i=0;i<10;i++)
        if(!vis[i])
            return false;
    return true;
}
int main(){
    bool tag=false;
    while(scanf("%d",&n)&&n){
        if(tag)
            printf("\n");
        else
            tag=true;
        int flag=0;
        for(int a=10000;a<100000;a+=10000){
            for(int b=0;b<10000;b+=1000){
                for(int c=0;c<1000;c+=100){
                    for(int d=0;d<100;d+=10){
                        for(int e=0;e<10;e+=1){
                            memset(vis,0,sizeof(vis));
                            int k=a+b+c+d+e;
                            if(judge(k))
                            {
                                flag=1;
                                printf("%5d / %05d = %d\n",k,k/n,n);
                            }
                        }
                    }
                }
            }
        }
        if(!flag)
            printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
