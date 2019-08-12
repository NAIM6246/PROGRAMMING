#include<bits/stdc++.h>
using namespace std;
int main(){
string s,x,z="";
int n,t=0;
while(cin>>s && s!="E-N-D"){
    if(t<s.size()){
        bool f=0,y=0;int a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i] <= 'Z' )
                {a++;z+=tolower(s[i]);}

            else if(s[i]>='0' && s[i]<='9' || s[i]=='-')
            {a++;z+=s[i];}
            else if(i>0 && i<s.size()-1)
            {
               f=1;
               break;
            }
        }
        if(!f){
            x=z;
            //cout<<"HIsdfds"<<endl;
            t=s.size();
        }
        else if(f && a>t){
            x=z;
            //cout<<"HI"<<endl;
            //x.erase(a);
            t=a;
        }
        z="";
    }
}
for(int i=0;i<x.size();i++){
////    if(x[i]>='A' && x[i]<='Z'){
////        x[i]=tolower(x[i]);
////    }
    cout<<x[i];
}
cout<<endl;
return 0;
}
