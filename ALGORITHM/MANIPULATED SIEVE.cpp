#include<bits/stdc++.h>
using namespace std;
const long long Max = 1000001;
vector<long long>isprime(Max,true);
vector<long long>prime;
vector<long long>spf(Max);///spf => smallest prime factor of i th number
void manipulatedSieve(long long n)
{
    isprime[0]=isprime[1]=false;
    for(long long i=2; i<n; i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            spf[i]=i;
        }
        for(long long j=0 ; j<prime.size() &&  i*prime[j]<n && prime[j]<=spf[i] ; j++)
        {
            isprime[i*prime[j]]=false;
            spf[i*prime[j]]=prime[j];
        }
    }
}
int main()
{
    long long n;
    cin>>n;
    manipulatedSieve(n);
    for(int i=0; i<prime.size() && prime[i]<=n; i++)
        cout<<prime[i]<<endl;
    return 0;
}
