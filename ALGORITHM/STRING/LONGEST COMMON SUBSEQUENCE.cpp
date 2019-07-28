#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
cin>>s1>>s2;
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
cout<<"Number of character : "<<a[n][m]<<endl;
string s="";
for(int i=n,j=m;a[i][j]!=0 && i>=0 && j>=0;){
    if(s1[i-1] == s2[j-1]){
        s+=s1[i-1];
        i--,j--;

    }
    else if(a[i][j] == a[i-1][j]){
        i--;
    }
    else{
        j--;
    }
}
reverse(s.begin(),s.end());
cout<<"Subsequence : "<<s<<endl;
return 0;
}
