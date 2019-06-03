#include<bits/stdc++.h>
using namespace std;
void PrimeFactors(long long n)
{
    long long x,y,z,c;
    cout<<n<<" = ";
    if(n<0)
    {
        cout<<"-1 x ";
        n=abs(n);
    }
    c=n;
    if(n%2==0)
    {
        while(n%2==0)
        {
            n/=2;
            if(n>1)
                cout<<"2 x ";
            else
                cout<<"2"<<endl;
        }
    }
    for(long long i=3; i*i<=c; i+=2)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                if(n>1)
                    cout<<i<<" x ";
                else
                    cout<<i<<endl;
            }
        }
    }
    if(n>1)
        cout<<n<<endl;
}
int main()
{
    long long n;
    while(cin>>n && n!=0)
    {
        PrimeFactors(n);
    }
    return 0;
}

