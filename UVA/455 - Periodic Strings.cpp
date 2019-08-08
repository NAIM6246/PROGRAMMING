#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
string x,s;
cin>>t;
getchar();
for(int i=0;i<t;i++){
    //cout<<i+1<<"=> ";
    getline(cin,x);
    getline(cin,s);
    string a="";
    a+=s[0];
    //cout<<a<<endl;
    int k=0;
    for(int j=0;j<s.size();j++){
        //cout<<" asdfasdf ";
        if(s[j]==a[k]){
            //cout<<"HI"<<endl;
            if(j==s.size()-1 && k<a.size()-1){
                a=s;

               // cout<<"HI "<<k<<endl;
            }
            k++;
            if(k==a.size() && j<s.size()-1)
                k=0;
        }
        else{
            //k=0;
            a=s;
            if(s[j]==a[0]){
            a.erase(j);k=1;}//cout<<"x "<<a<<" "<<j+1<<endl;k=1;}
            else
            {a.erase(j+1);k=0;}//cout<<"sDF "<<s[j]<<" "<<a<<" "<<j+1<<endl;k=0;}
        //    cout<<"hello"<<endl;
//            cout<<a<<endl;
        }
      //  cout<<"HI "<<a.size()<<" "<<j+1<<endl;
    }
    cout<<a.size()<<endl;
    if(i<t-1)
        cout<<endl;
}
return 0;
}
