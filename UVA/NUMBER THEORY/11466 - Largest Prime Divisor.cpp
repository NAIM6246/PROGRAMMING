#include<bits/stdc++.h>
using namespace std;
const long long Max = 100000001;
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

pair<bool,long long> checkPrime(long long b){
    if(b%2==0)
        return make_pair(0,2);
    bool f=0;
    long long m;
    for(long long i=3;i*i<=b;i+=2)
        if(b%i==0)
        {
            f=1;
            m=i;
            break;
        }
    if(f==1)
        return make_pair(0,m);
    else
        return make_pair(1,-1);
}

int main()
{
    long long n;
    manipulatedSieve(10000000);
    while(cin>>n && n!=0)
    {
        n=abs(n);
        bool flag=0,p=0;
        long long b;
        if(n==1)
            flag=1;
        else{
        long long x=2;
            long long a=n,w=0;
        for(long long i=0; i<prime.size() && prime[i]<=n; i++)
        {
            if(a%x==0){
                    w++;
                while(a%x==0){
                    a/=x;
                }
                b=a;//<<b<<endl;
                if(w>1 && b==1)
                {
                    b=x;
                    p=1;
                    break;
                }
                if(b==1 && w==1)
                {
                    flag=1;
                    break;
                }
                else{
                    pair<bool ,long long> q;
                    q = checkPrime(b);
                    if(q.first){
                        p=1;
                        break;
                    }
                    else{
                        x=q.second;
                    }
                }
            }
            else{
                x=prime[i+1];
            }
        }
        if(a==n)
            flag=1;
        }
        if(flag)
            cout<<"-1"<<endl;
        else if(p)
            cout<<b<<endl;
    }
    return 0;
}
