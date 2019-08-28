#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,char>&a,const pair<int,char>&b){
    if(a.first>b.first)
        return 1;
    else if(a.first<b.first)
        return 0;
    else
        return (bool)(a.second<b.second);
}
int main()
{
    int n;
    while(cin>>n)
    {
        getchar();
        string s="",a;
        for(int i=0;i<n;i++){
            getline(cin,a);
            s+=a;
        }
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
                m[toupper(s[i])]++;
        }
        vector<pair<int,char> >v;
        for(char i='A';i<='Z';i++){
            if(m[i]>0)
            v.push_back({m[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            cout<<v[i].second<<" "<<v[i].first<<endl;
        }
    }
    return 0;
}
