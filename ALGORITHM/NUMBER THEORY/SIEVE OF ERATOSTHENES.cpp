/*
    sieve of erastosthenes modified and efficient O(n)

*/
#include<bits/stdc++.h>
using namespace std;
bool prime[1000005];
void SieveOfEratosthenes(int n)
{
    memset(prime,true,n);
    for(int i=4;i<=n;i+=2)
        prime[i]=0;
    for(int i=3; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i; j<=n; j+=(i+i))
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
    for(int i=2; i<=n; i++)
    {
        if(prime[i])
            cout<<i<<endl;
    }
}
