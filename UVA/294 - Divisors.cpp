#include<bits/stdc++.h>
using namespace std;
long long Divisors(long long n)
{
    long long a=2,c=n;
    for(long long i=2;i*i<=c;i++){
        if(n%i==0)
        {
            a++;
            if(i!=(n/i))
                a++;
        }
    }
    return a;
}
int main()
{
    long long t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        long long l,h;
        cin>>l>>h;
        long long ans=0,num=0;
        for(long long i=l;i<=h;i++){
            long long x = Divisors(i);
            if(ans<x){
                ans = x;
                if(i==1)
                    ans=1;
                num=i;
            }
        }
        cout<<"Between "<<l<<" and "<<h<<", "<<num<<" has a maximum of "<<ans<<" divisors."<<endl;
    }
    return 0;
}
