#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        int seed=0,seed1=INT_MAX;
        set<int >x;
        while(seed1!=0){
            seed1=(seed+n)%m;
            seed=seed1;
            x.insert(seed1);
        }
        int a=n,b=m,sa=0,sb=0;
        while(a>0){
            a/=10;
            sa++;
        }
        while(b>0){
            b/=10;
            sb++;
        }
        for(int i=0;i<10-sa;i++)
            cout<<" ";
        cout<<n;
        for(int i=0;i<10-sb;i++)
            cout<<" ";
        cout<<m;
        for(int i=0;i<4;i++)
            cout<<" ";
        if(x.size()==(m))
            cout<<"Good Choice"<<endl;
        else
            cout<<"Bad Choice"<<endl;
        cout<<endl;
    }
return 0;
}
