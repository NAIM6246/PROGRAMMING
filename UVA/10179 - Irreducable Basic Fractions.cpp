#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005
ll phi(ll n){
    ll result  = n;
    if(n==1)return 0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            result -= result/i;
        }
    }
    if(n>1)result -= result/n;
    return result;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll a;
    while(cin>>a && a>0){
        cout<<phi(a)<<endl;
    }
    return 0;
}
