#include<bits/stdc++.h>
using namespace std;
long long Gcd(long long  a,long long b){
    if(a==0)
        return b;
    return Gcd(b%a,a);
}
int main(){
    int n,ca=1;
    while(cin>>n && n>0){
            cout<<"Case "<<ca<<":"<<endl;
    ca++;
        bool neg=0,ne=0;
        long long a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            cin>>c;
            a+=c;
        }
        b=n;
        if(a<0){
            neg=1;
            a=(-1)*a;
        }
        float x,y;
        long long q=a/b,e=a%b,g=b;
        if(e!=0){
        long long h = Gcd(e,g);
        e=e/h;g=g/h;
        long long o=g,l=0,m=0,p=q,r=e,w=0;
        while(o>0){
            o/=10;
            l++;
        }
        while(p>0){
            p/=10;
            m++;
        }
        while(r>0){
            r/=10;
            w++;
        }
        if(neg==1)
            cout<<"  ";
        for(int i=1;i<=l+m-w;i++)
            cout<<" ";
        cout<<e<<endl;
        if(neg)
            cout<<"- ";
        if(q!=0)
        cout<<q;
        for(int i=1;i<=l;i++)
            cout<<"-";
        cout<<endl;
        if(neg)
            cout<<"  ";
        for(int i=1;i<=m;i++)
            cout<<" ";
        cout<<g<<endl;
        }
        else{
            if(neg)
                cout<<"- "<<q<<endl;
            else
                cout<<q<<endl;
        }

    }
return 0;
}
