#include<bits/stdc++.h>
using namespace std;
bool prime[40005];
map<int , bool>m;
void Sieve( int n){
    memset(prime,1,sizeof(prime));
    prime[0]=0;
    prime[1]=0;
    for(int i=4;i<=n;i+=2)
        prime[i]=0;
    for(int i=3;i*i<=n;i+=2){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i+i)
                prime[j]=0;
        }
    }
}
int main(){
    int n;
    Sieve(40000);
    while(cin>>n && n!=0){

    m[2]=1;
    for(int i=3;i<=n;i+=2)
    {
        if(prime[i]){
            m[i]=1;
        }
    }
        int a=0;
        if(n==4){
            a++;
            m[2]=0;
        }
        for(int i=3;i<=n;i++){
            if(prime[i] && prime[n-i] && (m[i]!=0 || m[n-i]!=0) )
            {
                a++;
                m[i]=0;
                m[n-i]=0;
            }
        }
        cout<<a<<endl;
    }
return 0;
}
