#include<bits/stdc++.h>
using namespace std;
    long long b[1005];
long long HI(long long a){
    int i=0;
    while(b[i]<a){
        i++;
    }
    return a-b[i-1];
}
int main(){
    map<long long,int >m;
    m[1]=1;m[2]=1;
    b[0]=1;b[1]=2;
    int c=2;
    long long f2=0,f1=2,f0=1;
    while(c<70){
        f2= f1+f0;
        m[f2]=1;
        b[c]=f2;
        c++;
        f0=f1;f1=f2;
    }
    int t;
    cin>>t;
    for(int h=1;h<=t;h++){
        int n;
        cin>>n;
        long long a[n];
        long long ans=1;
        for(int i=0;i<n;i++){
                long long x=0,y=0;
            cin>>a[i];
            if(m[a[i]]==1)
                x=1;
            else{
                int q=a[i],l=0;

                while(m[q]!=1){
                    int w = HI(q);
                    q=w;l++;
                }
                y=l+1;
                x=y;
            }
            ans*=x;

        }
        cout<<"Case "<<h<<": "<<ans<<endl;
    }
return 0;
}
