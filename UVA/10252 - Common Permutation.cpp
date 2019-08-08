#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
while(getline(cin,s1) && getline(cin,s2)){
    map<char ,long>m,n;
    for(int i=0;i<s1.size();i++)
        m[s1[i]]++;
    for(int i=0;i<s2.size();i++)
        n[s2[i]]++;
    long a=0;
    for(char i='a';i<='z';i++){
        a=min(m[i],n[i]);
        for(int j=0;j<a;j++)
            cout<<i;
    }
    cout<<endl;
}

return 0;
}
