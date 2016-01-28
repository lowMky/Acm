/*
ID: onlyazh1
LANG: C++
TASK: friday
*/

#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
int daysofmonth[13][2] = {{0, 0},{31, 31},{28, 29},{31, 31},{30, 30},{31, 31},{30, 30},{31, 31},{31, 31},{30, 30},{31, 31},{30, 30},{31, 31}};

bool isleap(int x){
    return ((x%4==0&&x%100!=0)||x%400==0);
}

int main(){
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");

    ifstream cin("friday.in");
    ofstream cout("friday.out");
    int n,d[8];
    cin>>n;
    int days=0;
    for(int i=1;i<=7;i++)
        d[i]=0;
    for(int i=0;i<n;i++){
        int t=isleap(1900+i);
        for(int j=1;j<=12;j++){
            d[(days+12)%7+1]++;
            days+=daysofmonth[j][t];
        }
    }
    cout<<d[6]<<" "<<d[7]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<" "<<d[4]<<" "<<d[5]<<endl;
    return 0;
}
