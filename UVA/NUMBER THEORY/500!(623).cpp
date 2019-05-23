#include<bits/stdc++.h>
using namespace std;

vector<int>res;
void factorial(long long x)
{
    long long carry=0,prod;
    for(long long j=0; j<res.size(); j++)
    {
        prod = res[j]*x + carry;
        res[j] = prod%10;
        carry=prod/10;
    }
    while(carry>0)
    {
        res.push_back(carry%10);
        carry=carry/10;
    }
}


int main()
{
    long long n;
    while(cin>>n){
    res.push_back(1);
    for(long long i=2; i<=n; i++)
    {
        factorial(i);
    }
    printf("%d!\n",n);
    for(long long i=res.size()-1; i>=0; i--)
        printf("%d",res[i]);
    printf("\n");
    }
    return 0;
}
