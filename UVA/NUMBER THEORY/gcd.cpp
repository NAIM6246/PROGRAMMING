#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return(gcd(b%a,a));
}
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        int g=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                g+=gcd(i,j);
            }
        }
        printf("%d\n",g);
    }
    return 0;
}
