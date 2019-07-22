#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c;
    while(cin>>n>>m>>c && n>0 && m>0){
    long long ans=0,x=0;
    bool komaisi =0,baraisi=0;
    int a=n,b=m;
    if(c==0)
        m--,komaisi=1;
    if(m>=8)
    x=(m-8)/2 +1;
    else x=0;
    long long y,yy, xx;
    //if(b>8)
    xx = (n-8)/2 +1;
    if(komaisi)
    {
        m++;
    }
    else
        m--;
    if(m>=8)
    y = (m-8)/2 +1;
    else y=0;
    yy = (n-7)/2 ;
    ans = y*yy + x*xx;
    cout<<ans<<endl;
    }
    return 0;
}
