#include<bits/stdc++.h>
using namespace std;
int main(){
string pa,st,mi,s;
while(getline(cin,st)){
    pa=st;
    s=st;
    reverse(pa.begin(),pa.end());
    bool palindrome=0,mirrored=0;
    if(pa == st)
        palindrome=1;
    bool no=0,ch=0;
    for(int i=0;i<st.size();i++){
        if(st[i]=='B' || st[i]=='C' || st[i]=='D' || st[i]=='F' || st[i]=='G' || st[i]=='K' || st[i]=='N' || st[i]=='P' || st[i]=='Q' || st[i]=='R'){
            no=1;
            mirrored=0;
            break;
        }
        else if(st[i]=='J' && st[st.size()-i-1]!='L' || st[i]=='L' && st[st.size()-i-1]!='J'){
            no=1;mirrored=0;break;
        }
        else if(st[i]=='2' && st[st.size()-i-1]!='S' || st[i]=='S' && st[st.size()-i-1]!='2'){
            no=1;mirrored=0;break;cout<<"hello"<<endl;
        }
        else if(st[i]=='3' && st[st.size()-i-1]!='E' || st[i]=='E' && st[st.size()-i-1]!='3'){
            no=1;mirrored=0;break;
        }
        else if(st[i]=='5' && st[st.size()-i-1]!='Z' || st[i]=='Z' && st[st.size()-i-1]!='5'){
            no=1;mirrored=0;break;
        }
    }
    if(!no){///
    for(int i=0;i<st.size();i++){
        if(st[i]=='J'){
            st[i]='L';
        }
        else if(st[i]=='2'){
            st[i]='S';
        }
        else if(st[i]=='3'){
            st[i]='E';
        }
        else if(st[i]=='5'){
            st[i]='Z';
        }
    }
        ///
        cout<<"hi"<<endl;
        mi=st;
        reverse(mi.begin(),mi.end());
        if(mi==st)
            mirrored=1;
    }
    if(palindrome && mirrored){
        cout<<s<<" -- is a mirrored palindrome."<<endl;
    }
    else if(palindrome){
        cout<<s<<" -- is a regular palindrome."<<endl;
    }
    else if(mirrored){
        cout<<s<<" -- is a mirrored string."<<endl;
    }
    else{
        cout<<s<<" -- is not a palindrome."<<endl;
    }
}
return 0;
}
