#include<bits/stdc++.h>
using namespace std;
int compare(const void* a,const void* b){
    const int* x=(int*)a;
    const int* y=(int*)b;
    if(*x>*y)
        return 1;
    else if(*x<*y)
        return -1;
    return 0;
}
int main(){
int n;
cin>>n;
int v[n];
//vector<int>v;
for(int i=0;i<n;i++){
cin>>v[i];
}
cout<<"before sorting"<<endl;
for(int i=0;i<n;i++)
cout<<v[i]<<" ";
cout<<endl;
qsort(&v,n,sizeof(int),compare);

cout<<"after sorting"<<endl;
for(int i=0;i<n;i++)
cout<<v[i]<<" ";
cout<<endl;
return 0;
}
