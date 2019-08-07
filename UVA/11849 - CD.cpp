#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m,a;
    while(cin>>n>>m && (n>0 || m>0) ){
        map<long long,long long>mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        for(int i=0;i<m;i++){
            cin>>a;
            mp[a]++;
            if(mp[a]>1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
