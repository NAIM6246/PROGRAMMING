#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        vector<int>v;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            ans+=abs(v[i]-v[i+1]);
        }
        ans+=abs(v[0]-v[n-1]);
        cout<<ans<<endl;

    }
    return 0;
}
