#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,e;
        cin>>n>>e;
        if(n>e)
            cout<<e<<endl;
        else{
            long long a=n-1,x;
            e-=a;
            for(int i=1;i<=n-2 && e>0;i++){
                a+=(i);
                e-=i;
                x=i+2;
            }
            cout<<n-x<<endl;
        }
    }
return 0;
}
