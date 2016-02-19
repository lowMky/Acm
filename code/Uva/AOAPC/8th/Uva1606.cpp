
#include<bits/stdc++.h>

using namespace std;
struct Point{
    int x,y;
    int tag;
    double rad;
    bool operator<(const Point &rhs)const{
        return rad<rhs.rad;
    }
};
Point P[1010],tmp[1010];

int cross(const Point &a,const Point &b){
    return a.x*b.y-b.x*a.y;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++)
            cin>>P[i].x>>P[i].y>>P[i].tag;

        int ans=0;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                tmp[k].x=P[j].x-P[i].x;
                tmp[k].y=P[j].y-P[i].y;
                tmp[k].tag=P[j].tag;
                if(tmp[k].tag){
                    tmp[k].x*=-1;
                    tmp[k].y*=-1;
                }
                tmp[k].rad=atan2(tmp[k].y,tmp[k].x);
                k++;
            }
            sort(tmp,tmp+k);
            int L=0,R=0,cnt=2;
            while(L<k){
                if(R==L){
                    R=(R+1)%k;
                    cnt++;
                }
                while(R!=L&&cross(tmp[L],tmp[R])>=0){
                    R=(R+1)%k;
                    cnt++;
                }
                cnt--;
                L++;
                ans=max(ans,cnt);

            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
