#include<bits/stdc++.h>
using namespace std;
int prime[1000007];
void Seive(int x)
{
    for(int i=0;i<=x;i++)
        prime[i]=-1;
    prime[0]=0;
    prime[1]=1;
    for(int i=4; i<=x; i+=2)
        if(i%4==0)
            prime[i]=0;
        else
            prime[i]=1;
    for(int i=3; i*2<=x; i+=2)
    {
        if(prime[i]==-1){
        for(int j=i*2; j<=x; j+=(i))
        {
            if(prime[j]==0)continue;
            else if(j%(i*i)==0)
                prime[j]=0;
            else if(prime[j]==-1 )
                prime[j]=1;
            else if(prime[j]>0)
                prime[j]++;
        }
        }
    }
}
int main()
{
    unsigned int n,temp=0;
    vector<int>v;
    freopen("input.txt","r",stdin);
    while(cin>>n && n)
    {
        if(temp<n)
            temp=n;
        v.push_back(n);
    }
    Seive(temp);
    for(int m=0;m<v.size();m++){
        n=v[m];
        int M=1,s=1;

        for(int i=2;i<=n;i++){
            if(prime[i]>0 && prime[i]%2!=0)
            {
                M=-1;
                s--;
            }
            else if(prime[i]>0 && prime[i]%2==0)
            {
                M=1;
                s++;
            }
            else{
                M=prime[i];
                s+=M;
            }
        }
        char x[10],y[10],z[10];
        sprintf(x,"%ud",n);
        sprintf(y,"%d",M);
        sprintf(z,"%d",s);
        int w = strlen(x) , e = strlen(y) , r = strlen(z);
        for(int i=0;i<=8-w;i++)
            printf(" ");
        cout<<n;
        if(M<0)
            cout<<"      "<<M;
        else
            cout<<"       "<<M;
        for(int i=1;i<=8-r;i++)
            cout<<" ";
        cout<<s<<endl;
    }
    return 0;
}
