#include<bits/stdc++.h>
using namespace std;
    bool prime[1000005];
bool SieveOfEratosthenes(int n)
{
    memset(prime,true,n);
    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2; j<=n; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    SieveOfEratosthenes(n);
    for(int i=2;i<=n;i++){
        if(prime[i])
            cout<<i<<endl;
    }
}
