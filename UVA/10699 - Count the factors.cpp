#include<bits/stdc++.h>
using namespace std;
long long Factors(long long n){
    long long c=n,ans=0;
    if(n%2==0){
        ans++;
        while(n%2==0){
            n/=2;
        }
    }
    for(long long i=3;i*i<=c;i+=2)
    {
        if(n%i==0){
            ans++;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1)
        ans++;
    return ans;
}
int main(){
    long long n;
    while(cin>>n && n!=0){
        long long ans = Factors(n);
        cout<<n<<" : "<<ans<<endl;
    }

return 0;
}
