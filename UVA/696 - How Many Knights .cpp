#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,m;
    while(cin>>n>>m && (n>0 || m>0) )
    {
        if( (n<3 || m<3) && m!=n)
        {
            bool flag=0;
            if(n<m){
                swap(n,m);flag=1;}
            bool a[(int)n][(int)m];
            memset(a,1,sizeof(a));
            int ans=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(a[i][j])
                    {
                        ans++;
                        if(i-1>=0)
                        {
                            if(j+2<m)
                                a[i-1][j+2]=0;
                            if(j-2>=0)
                                a[i-1][j-2]=0;
                        }
                        if(i+1<n)
                        {
                            if(j+2<m)
                                a[i+1][j+2]=0;
                            if(j-2>=0)
                                a[i+1][j-2]=0;
                        }
                        if(i+2<n)
                        {
                            if(j+1<m)
                                a[i+2][j+1]=0;
                            if(j-1>=0)
                                a[i+2][j-1]=0;
                        }
                        if(i-2>=0)
                        {
                            if(j+1<m)
                                a[i-2][j+1]=0;
                            if(j-1>=0)
                                a[i-2][j-1]=0;
                        }
                    }
                }
            }
            if(flag)
                swap(n,m);
            cout<<ans<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
        else if(n==2 && m==2)
            cout<<"4 knights may be placed on a 2 row 2 column board."<<endl;
        else
        {
            double ans,x,y,a,b;
            x = ceil(m/2.0);
            y = floor(m/2.0);
            a = ceil(n/2.0);
            b = floor(n/2.0);
            ans = a*x+b*y;
            cout<<ans<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
    }
    return 0;
}
