#include<bits/stdc++.h>
using namespace std;
vector<long long>twins;
bool CheckPrime(long long n,long long pos){
    return
        (bool) ( n & (1<<pos) );
}
long long Set(long long n,long long pos){
    return  ( n | (1<<pos) );
}

void BitWiseSieve(long long n){
    long long prime[n/32+5];
    memset(prime,0,sizeof(prime));
    for(long long i=3;i*i<=n;i+=2){
        if(CheckPrime( prime[i>>5],i&31) == 0 ){
            for(long long j = i*i ; j<=n ; j+=(i<<1)){
                prime[j>>5] = Set(prime[j>>5],j&31);
            }
        }
    }

    for(long long i=3;i<=n;i+=2){
        if(CheckPrime(prime[i>>5],i&31)==0)
        {
            long long x=i+2;
            if(CheckPrime(prime[x>>5],x&31)==0)
                    {
                    twins.push_back(i);
                    }
        }
    }
}

int main(){
BitWiseSieve(20000000);
long long n;
while(cin>>n){
    printf("(%lld, %lld)\n",twins[n-1],twins[n-1]+2);
}
return 0;
}
