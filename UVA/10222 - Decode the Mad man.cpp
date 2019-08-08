#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
string a="1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./";
map<char,char>m;
m['3']='1';
m['4']='2';
m['5']='3';
m['6']='4';
m['7']='5';
m['8']='6';
m['9']='7';
m['0']='8';
m['-']='9';
m['=']='0';
m['e']='q';
m['r']='w';
m['t']='e';
m['y']='r';
m['u']='t';
m['i']='y';
m['o']='u';
m['p']='i';
m['[']='o';
m[']']='p';
m['\\']='[';
m['d']='a';
m['f']='s';
m['g']='d';
m['h']='f';
m['j']='g';
m['k']='h';
m['l']='j';
m[';']='k';
m['\''] ='l';
m['c']='z';
m['v']='x';
m['b']='c';
m['n']='v';
m['m']='b';
m[',']='n';
m['.']='m';
m['/']=',';
m[' ']=' ';
//cout<<x<<endl;
while(getline(cin,s)){
//cout<<m['\\']<<endl;
char x;
for(int i=0;i<s.size();i++){
    if(s[i]>=65 && s[i]<=90)
        s[i] = tolower(s[i]);
    cout<<m[s[i]];
}
cout<<endl;
}
return 0;
}
