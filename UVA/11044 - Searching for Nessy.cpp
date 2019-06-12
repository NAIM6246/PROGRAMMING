#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y,a,b;
    long long t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        a=ceil((x-2)/3);
        b=ceil((y-2)/3);
        long long x=a*b;
        cout<<x<<endl;
    }
    return 0;
}
