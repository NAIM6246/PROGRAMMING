#include<bits/stdc++.h>
using namespace std;
void PrimeFactors(long long n){
    long long x,y,z;
    if(n%2==0){
        cout<<"2"<<endl;
        while(n%2==0){
        n/=2;
        }
    }
    long long c=n;
    for(long long i=3;i*i<=c;i+=2){
        if(n%i==0){
            cout<<i<<endl;
            while(n%i==0)
                n/=i;
        }
    }
}
int main(){
    long long n;
    cin>>n;
    PrimeFactors(n);
return 0;
}
