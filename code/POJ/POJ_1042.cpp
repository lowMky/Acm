#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int idx,lef;
    Node(int _idx,int _lef){
        idx=_idx,lef=_lef;
    }
    bool operator <(const Node &a)const{
        if(lef<a.lef)
            return true;
        else if(lef==a.lef)
            return idx>a.idx;
        return false;
    }
};

int f[30],d[30],t[30];
int sum[30],ans[30];
int tot;
priority_queue<Node> Que;

int main(){
    //freopen("in.txt","r",stdin);
    int n,T,icase=0;
    while(cin>>n&&n){
        if(icase) cout<<endl;
        else icase++;
        tot=-1;
        memset(ans,0,sizeof(ans));
        cin>>T;
        for(int i=0;i<n;i++) cin>>f[i];
        for(int i=0;i<n;i++) cin>>d[i];
        for(int i=0;i<n;i++){
            if(!i) t[i]=0;
            else cin>>t[i];
            t[i]*=5; t[i]+=t[i-1];
        }
        for(int i=0;i<n;i++){
            int tlef=T*60;
            int tmp[30],tans=0;
            memset(tmp,0,sizeof(tmp));
            while(!Que.empty())
                Que.pop();
            tlef-=t[i];
            for(int j=0;j<=i;j++)
                if(f[j])
                    Que.push(Node(j,f[j]));
            while(tlef>0&&!Que.empty()){
                Node tt=Que.top();
                Que.pop();
                tans+=tt.lef;
                tmp[tt.idx]+=5;
                tlef-=5;
                if(tt.lef-d[tt.idx]>0)
                    Que.push(Node(tt.idx,tt.lef-d[tt.idx]));
            }
            tmp[0]+=tlef;
            if(tans>tot){
                tot=tans;
                for(int j=0;j<n;j++)
                    ans[j]=tmp[j];
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i];
            cout<<(i<n-1?", ":"\n");
        }
        cout<<"Number of fish expected: "<<tot<<endl;
    }
    return 0;
}
