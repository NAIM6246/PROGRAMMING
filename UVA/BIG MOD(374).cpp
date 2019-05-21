#include<bits/stdc++.h>
using namespace std;
int main(){
long long b,m,p;
//freopen("input.txt","r",stdin);
while(cin>>b>>p>>m){
    long long a,c,n;
    a=b;
    if(a==1 )
        cout<<"1"<<endl;
    else if(a==-1)
    {
        if(p%2==0)
            cout<<"1"<<endl;
        else
            cout<<"-1"<<endl;
    }
    else if(p==0){
        long long r = 1%m;
        cout<<r<<endl;
    }
    else{
        vector<int>bi,mod;
        long long d=p;
        while(d>0){
            bi.push_back(d%2);
            d/=2;
        }
        long long y=a%m,x=1;
        for(long long i=0;i<bi.size();i++){
            if(bi[i]==1)
                x=(x*y)%m;
            y=(y*y)%m;
        }
        cout<<(x%m+m)%m<<endl;
        bi.clear();
    }
}
return 0;
}
