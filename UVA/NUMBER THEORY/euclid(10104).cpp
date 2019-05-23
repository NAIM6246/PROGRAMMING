#include<bits/stdc++.h>
using namespace std;

long long Extgcd(long long n,long long m,long long *x,long long *y){
    if(n==0){
        *x=0;
        *y=1;
        return m;
    }
    long long x1,y1,gcd;
    gcd = Extgcd(m%n,n,&x1,&y1);
    *x = y1 - (m/n)*x1;
    *y = x1;
    return gcd;
}
int main()
{
    long long a,b;
    while(cin>>a>>b){
        long long x,y,g,p,q;p=a;q=b;
        g= Extgcd(a,b,&x,&y);
        if(x==1 && y==0 && p==q ){x=0;y=1;}
        printf("%lld %lld %lld\n",x,y,g);
    }
    return 0;
}
