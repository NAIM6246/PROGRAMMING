#include<bits/stdc++.h>
using namespace std;

vector<int>primes;
void Sieve(long long a)
{
    long long x=sqrt(a)+2;
    bool prime[x];
    prime[0]=0;
    prime[1]=0;
    memset(prime,1,sizeof(prime));
    for(int i=4; i<=x; i+=2)
        prime[i]=0;
    primes.push_back(2);
    for(int i=3; i<=x; i+=2)
    {
        if(prime[i])
        {
            primes.push_back(i);
            for(int j=i*i; j<=x; j+=i+i)
                prime[j]=0;
        }
    }
}
bool prime[1000005];
void primeInRange(long long l, long long h)
{
    prime[h-l+3];
    memset(prime,1,sizeof(prime));
    for(long long i=0; i<primes.size(); i++)
    {
        long long lo=floor(l/primes[i])*primes[i];
        if(lo<l)
            lo+=primes[i];
        if(lo==primes[i])
            lo+=primes[i];
        for(long long j=lo; j<=h; j+=primes[i])
        {
            prime[j-l]=0;
        }
    }
    if(l==1)
        prime[0]=0;
    long long d2=0,d1=INT_MAX,sd1=0,sd2=0,bd1=0,bd2=0,a,b=0;
    for(long long i=l; i<=h; i++)
    {
        if(prime[i-l])
        {
            a=b;
            b=i;
            if(a!=0)
            {
                long long x=b-a;
                if(x<d1)
                {
                    sd1=a;
                    sd2=b;
                    d1=x;
                }
                if(x>d2)
                {
                    bd1=a;
                    bd2=b;
                    d2=x;
                }
            }
        }
    }
    if(sd1==0 || sd2==0 || bd1==0 || bd2==0)
        printf("There are no adjacent primes.\n");
    else
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",sd1,sd2,bd1,bd2);
}
int main()
{
    int low,high;
    while(cin>>low>>high)
    {
        Sieve(high);
        primeInRange(low,high);
        primes.clear();
    }

    return 0;
}
