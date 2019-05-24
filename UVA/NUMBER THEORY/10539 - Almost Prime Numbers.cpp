#include<bits/stdc++.h>
using namespace std;
bool prime[1000007];
void Seive(long long x){
    memset(prime,1,x+1);
    prime[0]=0;
    prime[1]=0;
    for(int i=4;i<=x;i+=2)
        prime[i]=0;
    for(int i=3;i*i<=x;i+=2)
    {
        for(int j=i*i;j<=x;j+=(i+i)){
            prime[j]=0;
        }
    }
}
int main(){
    int n;
    //freopen("input.txt","r",stdin);
    cin>>n;
    while(n--){
        long long low,high;
        cin>>low>>high;
        long long x=sqrt(high);
        Seive(x);
        //cout<<"x "<<x<<endl;
        long long cnt=0,y=0;
        for(long long i=2;i<=x;i++){
            if(prime[i]){
                cout<<"prime => "<<i<<endl;
               // long long j=2;
                //cout<<pow(i,j )<<endl;
                long long q = pow(i,2);
                cout<<q<<" "<<pow(i,2)<<endl;
                while(q<=high){
                    //long long
                    if(q>=low)
                        {cnt++;
                    cout<<q<<endl;}
                    q*=i;
                }//cout<<i<<" "<<cnt-y<<endl;
            //y=cnt;
            }
        }
        cout<<cnt<<endl;
    }
return 0;
}
