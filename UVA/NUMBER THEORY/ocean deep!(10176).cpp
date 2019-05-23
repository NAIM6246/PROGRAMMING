#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="",u;
    while(cin>>u)
    {
        s+=u;
        if(u[u.size()-1]!='#')
        {
            while(1)
            {
                cin>>u;
                s+=u;
                if(u[u.size()-1]=='#')
                {
                    break;
                }
            }
        }
        int a,c,n;
        a=s.size();
        if(a-1==1)
        {
            if(s[0]=='1')
                cout<<"NO"<<endl;
            else if(s[0]=='0')
                cout<<"YES"<<endl;
        }
        else
        {
            unsigned long long m = 131071,x=1,sx=0,sxx=1;
            for(long long i=s.size()-2,q=0; i>=0 ; i--,q++)
            {
                if(s[i]=='1')
                {
                    vector<int>bi,temp;
                    long long d=q;
                    while(d>0)
                    {
                        bi.push_back(d%2);
                        d/=2;
                    }
                    x=2%m;
                    sxx=1;
                    for(long long j=0; j<bi.size(); j++)
                    {
                        if(bi[j]==1)
                            sxx=(sxx*x)%m;
                        x=(x*x)%m;
                    }
                    sx=(sx+sxx);
                    if(sx%m==0)
                        sx=sx%m;
                    bi.clear();
                }
            }
            if(sx%m==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        s.clear();
        u.clear();
    }
    return 0;
}
