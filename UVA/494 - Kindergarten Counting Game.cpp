#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
while(getline(cin,s)){
    int ans=0;
    bool f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'
            || i<s.size()-1 && s[i]=='-' && s[i+1]!='-')
        {
            f=1;

        }
        else if(f==1){

                cout<<ans+1<<" "<<s[i]<<endl;
            ans++;
            f=0;
        }
    }
    cout<<ans<<endl;
}

return 0;
}
