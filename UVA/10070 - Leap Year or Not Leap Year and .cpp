#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
int q=0;
while(cin>>s){
    int  l=0,si=0;
    if(q>0)
        cout<<endl;
    q=1;
    l+=( (s[s.size()-4]-'0')*1000 + (s[s.size()-3]-'0')*100 + (s[s.size()-2]-'0')*10 + (s[s.size()-1]-'0') );
    si+=( (s[s.size()-2]-'0')*10 + (s[s.size()-1]-'0') );
    bool le=0,h=0,b=0;
    if(si%4==0 && l%100!=0 || l%100==0 && l%400==0){
        le=1;
    }
    long long x=0,y=0,carry=0,z=0,m=0;
    x+=( (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0') );
    m=x;
    for(long long i=3;i<s.size();){
        y=x%55;
        z=m%15;
        x=(y*10 + s[i]-'0');
        m=(z*10 + s[i]-'0');
        i++;
        if(i+1<s.size()){
            x=(x*10 + s[i]-'0');
            m=(m*10 + s[i]-'0');
            i++;
        }
        if(i==s.size()){
            if(le && x%55==0)
                {b=1;}
            if(m%15==0)
                {h=1;}
        }
    }
    if(le)
        cout<<"This is leap year."<<endl;
    if(h)
        cout<<"This is huluculu festival year."<<endl;
    if(b)
        cout<<"This is bulukulu festival year."<<endl;
    if(!le && !h && !b)
        cout<<"This is an ordinary year."<<endl;
}
return 0;
}
