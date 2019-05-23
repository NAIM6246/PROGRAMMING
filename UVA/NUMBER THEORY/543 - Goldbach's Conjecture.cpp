#include<bits/stdc++.h>
using namespace std;
bool prime[1000005];
void SieveOfEratosthenes(int n)
{
    memset(prime,1,n);
    prime[0]=0;
    prime[1]=0;
    for(int i=4;i<=n;i+=2)
        prime[i]=0;
    for(int i=3; i*i<=n; i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i; j<=n; j=j+i+i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        SieveOfEratosthenes(n);
        int x,y;
        bool flag=0;
        for(int i=2;i*2<=n;i++){
            if(prime[i] && prime[n-i])
            {
                flag=1;
                x=i;
                y=n-i;
                break;
            }
        }
        if(flag)
            cout<<n<<" = "<<x<<" + "<<y<<endl;
        else cout<<"Goldbach's conjecture is wrong."<<endl;
    }
    return 0;
}
