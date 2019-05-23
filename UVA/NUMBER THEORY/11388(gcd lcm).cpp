#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
while(t--){
    long long g,l;
    scanf("%lld %lld",&g,&l);
    long long a,b,s;
    s=g*l;
    if(s%(g*g)==0){
        a=s/g;
        b=g;
        if(a>b){
            long long te;
            te=a;
            a=b;
            b=te;
        }
        printf("%lld %lld\n",a,b);
    }
    else{
        printf("-1\n");
    }
}
return 0;
}
