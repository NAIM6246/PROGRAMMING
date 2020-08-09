#include<bits/stdc++.h>
using namespace std;
#define fast     ios::sync_with_stdio(0);cin.tie(0);
#define mx 2000005
#define ll long long
ll dept[mx+1],phi[mx+1];
void phi_all(ll n){
    for(ll i =1;i<=n;i++)phi[i]=i;
    for(ll i=2;i<=n;i++){
        if(phi[i]==i){
            for(ll j = i;j<=n;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

ll depthPhi(ll n){
    if(dept[n]!=0)return dept[n];
    ll x = phi[n];
    dept[n] = depthPhi(x)+1;
    return dept[n];
}

int main(){
    ll t;
    scanf("%lld",&t);
    dept[1]=dept[2]=1;
    phi_all(mx-1);
    while(t--){
        ll n,m,sum=0;
        scanf("%lld%lld",&n,&m);
        for(ll i=n;i<=m;i++){
            sum+=depthPhi(i);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
