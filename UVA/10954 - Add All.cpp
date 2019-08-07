#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    while(cin>>n && n>0)
    {
        long long a,s=0,b,c,d;
        priority_queue<long long, vector<long long>,greater<long long> >p;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            p.push(a);
        }
        for(int i=1; i<n; i++)
        {
            b=p.top();
            p.pop();
            c=p.top();
            p.pop();
            d= b+c;
            s+=d;
            p.push(d);
        }
        cout<<s<<endl;
    }

    return 0;
}
