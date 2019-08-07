#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
while(getline(cin,s1) && getline(cin,s2)){
int m=s2.size() ;
int n = s1.size();
int a[n+1][m+1];
for(int i=0;i<s1.size()+1;i++){
    for(int j=0;j<s2.size()+1;j++){
        if(i==0 || j==0)
            a[i][j]=0;
        else if(s1[i-1]==s2[j-1]){
            a[i][j] = a[i-1][j-1]+1;
        }
        else{
            a[i][j] = max(a[i][j-1],a[i-1][j]);
        }
    }
}
cout<<a[n][m]<<endl;
}
return 0;
}
