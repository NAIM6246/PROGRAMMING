#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q=0;
    while(cin>>n){
        if(q>0)
            cout<<endl;
        getchar();
        string s[10],a,d;
        for(int i=0;i<n;i++)
            cin>>s[i];
        map<string,int>m,mm;
        int b,c;
        for(int i=0;i<n;i++){
            //getchar();
            cin>>a;
            cin>>b>>c;
            //getchar();
            m[a]+=b;mm[a]+=b;
            //cout<<a<<" "<<m[a]<<" "<<mm[a]<<endl;
            for(int j=0;j<c;j++){
                cin>>d;
                mm[d]+=(b/c);
                mm[a]-=(b/c);
            }
           /* if(c>0){
            mm[a]+=(b%c);
            //m[a]-=(b%c);

            }*/
        }
        for(int i=0;i<n;i++){
            cout<<s[i]<<" ";cout<<mm[s[i] ]-m[s[i] ]<<endl;
            //else cout<<m[s[i] ]<<endl;
        }
        q=1;
    }
return 0;
}
