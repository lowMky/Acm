#include <iostream>

using namespace std;

char s[200100];
int ss[200100];
int main()
{
    int n;cin>>n;
    cin>>s;
    for(int i=0;i<n;++i)
        cin>>ss[i];

    int ans=1e9+7;
    for(int i=0;i<n-1;++i)
        if(s[i]=='R'&&s[i+1]=='L')
            ans=min(ans,ss[i+1]/2-ss[i]/2);
    if(ans<1e9+7) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
