#include<bits/stdc++.h>
using namespace std;
bool Prime[1000000+5];
void Seive(long long n){
    memset(Prime,1,sizeof(Prime));
    Prime[0]=Prime[1]=0;
    for(int i=4;i<=n;i+=2)
        Prime[i]=0;
    for(int i=3;i*i<=n;i+=2){
        if(Prime[i]){
            for(int j=i*i;j<=n;j+=(i+i))
                Prime[j]=0;
        }
    }
}
int main(){
    long long n;
    Seive(1000000);
    while(cin>>n && n!=0){
        bool x=0;
        for(int i=2;i<=n;i++){
            if(Prime[i] && Prime[n-i])
            {
                cout<<n<<":"<<endl;
                cout<<i<<"+"<<n-i<<endl;
                x=1;
                break;
            }
        }
        if(!x)
            cout<<n<<":"<<endl<<"NO WAY!"<<endl;
    }
return 0;
}
