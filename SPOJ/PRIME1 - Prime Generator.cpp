#include<bits/stdc++.h>
using namespace std;
vector<long long>prime;
void manipulatedSieve(long long l, long long h)
{
    long long x=sqrt(h)+1;
    bool mark[x];
    memset(mark,1,sizeof(mark));
    for(long long i=4;i<=x;i+=2)
        mark[i]=0;
    prime.push_back(2);
    for(long long i=3;i<=x;i+=2)
    {
        if(mark[i]){
            prime.push_back(i);
            for(long long j=i*i;j<=x;j+=i+i){
                mark[j]=0;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long l,h;
        cin>>l>>h;
        manipulatedSieve(l,h);
        bool mark[h-l+5];
        memset(mark,0,sizeof(mark));
//        cout<<prime.size()<<endl;
        for(long long i=0;i<prime.size();i++){
            long long x=floor(l/prime[i])*prime[i];

            if(x<l){
                x+=prime[i];
            }
            if(x==prime[i])
                x+=prime[i];
            for(long long j=x;j<=h;j+=prime[i]){
                mark[j-l]=1;
//                cout<<"ji "<<j<<endl;
            }
        }
        if(l==1)mark[0]=1;
        for(long long i=l;i<=h;i++){
            if(!mark[i-l])
                cout<<i<<endl;
        }

    }
    return 0;
}
