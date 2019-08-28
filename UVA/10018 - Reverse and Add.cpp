#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    string s,r,a;
    while(n--)
    {
        cin>>s;
        int i=0;
            r=s;
            reverse(r.begin(),r.end());
        while(r!=s){
            int carry=0,sum=0;
            for(int i = s.size()-1;i>=0;i--){
                sum = carry + (s[i]-'0') + (r[i]-'0');
                if(sum<10){
                    s[i]=sum+'0';carry=0;}
                else{
                    s[i]=sum%10+'0';
                    carry=sum/10;
                }
                if(i==0 && carry>0){
                    a+=(carry+'0');
                    s=a+s;
                    a="";
                }
            }
            r=s;
            reverse(r.begin(),r.end());
            i++;
        }
        cout<<i<<" "<<s<<endl;
    }
    return 0;
}
