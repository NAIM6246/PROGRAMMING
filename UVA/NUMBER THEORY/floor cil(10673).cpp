#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,k;
        scanf("%lld %lld",&x,&k);
        double c,e;
        c=floor(double(x)/double(k));
        e=ceil(double(x)/double(k));
        long long n=1,m=1,p,q,s,o,d,a,b;
        a=(long long)(c);
        b=(long long)(e);
        if(x<k)
        {
            m=0;
            n=1*x;
        }
        else
        {
            while(1)
            {
                if(x%a==0)
                {
                    m=x/a;
                    n=0;
                    break;
                }
                else if(x%b==0)
                {
                    m=0;
                    n=x/b;
                    break;
                }
                else
                {
                    d=x-a*m-b*n;
                    s=m*2;
                    o=n*2;
                    if(d==0)
                        break;
                    else if(d%a==0)
                    {
                        m+=(d/a);
                        n=n;
                        break;
                    }
                    else if(d%b==0)
                    {
                        n+=(d/b);
                        m=m;
                        break;
                    }
                    else if(x==(a*s+b*o))
                    {
                        m=s;
                        n=o;
                        break;
                    }
                    else if(x==(a*s+b))
                    {
                        m=s;
                        break;
                    }
                    else if(x==(a+b*o))
                    {
                        n=o;
                        break;
                    }
                    else
                    {
                        m++;
                        n++;
                    }
                }
            }
        }
        p=m;
        q=n;
        long long h= p*a+q*b;
        printf("%lld %lld\n",p,q);
    }
    return 0;
}
