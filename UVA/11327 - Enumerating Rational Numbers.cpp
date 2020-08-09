#include<bits/stdc++.h>
using namespace std;
#define fast     ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back
#define bg begin()
#define en end()
#define in(a) scanf("%d",&a)
#define inl(a) scanf("%lld",&a)
typedef vector<ll> VL;
typedef vector<int> V;
typedef pair<ll,ll> PLL;
typedef pair<int,int> P;
typedef map<int,int>M;
typedef map<ll,ll>MLL;
typedef map<char,int>MC;
//long long ub(ll pos,ll si,ll val){if(a[si]<val)return -1;ll l,r,mid,z;l=pos,r=si;while(l<=r){mid=(l+r)/2;if(a[mid]<=val){z= mid,l=mid+1;}else r= mid-1;}return z;}
//long long lb(ll pos,ll si,ll val){ll mid,l,r,z=0;l=pos,r=si;while(l<r){mid = (l+r)/2;if(a[mid]==val){z=mid;r=mid-1;}else if(a[mid]>val)r=mid-1;else l = mid+1;}return z;}
//ll nCr(ll n,ll m){long long z=1;for(int i=0;i<m;i++)z=z*(n-i)/(i+1);return z;}
#define mx 200005
ll phi[mx+1];
void phi_all(ll n){
    phi[0]=0;
    phi[1]=2;
    for(int i=2;i<mx;i++)phi[i]=i;
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
int main(){
    fast;
    phi_all(mx);
    ll n;
	while(cin>>n && n>0)
	{
        ll ans=0,i=0,z=0,j;
        for( i=1;i<=mx;i++){
            ans+=phi[i];
            if(ans>=n)break;
        }
        ans = n-ans + phi[i];
        for(j=0;z<ans;j++){
            z+=(__gcd(j,i)==1);
        }j--;
        cout<<j<<"/"<<i<<endl;
	}
	return 0;
}
