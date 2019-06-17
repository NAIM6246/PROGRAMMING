#include<bits/stdc++.h>
using namespace std;
int Gcd(int a,int b){
    if(a==0)return b;
    return Gcd(b%a,a);
}
int main(){
    int t;
    cin>>t;
    char x[2];
    while(t--){
        string s;
    gets(x);
        getline(cin,s);
        int n=0;
        vector<int >a;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                n*=10;
                n+=(s[i]-'0');
            }
            else
            {
                a.push_back(n);
                n=0;
            }
        }
        a.push_back(n);
        int g=0;
        for(int i=1;i<a.size();i++){
            for(int j=0;j<i;j++){
                g=max(g,Gcd(a[j],a[i]));
            }
        }
        cout<<g<<endl;
    a.clear();
    s.clear();
    }
return 0;
}
