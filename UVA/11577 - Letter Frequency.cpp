#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<char,int>&a, const pair<char,int>&b){
    if(a.second==b.second)
        return (a.first<b.first);
    return (a.second>b.second);
}
int main(){
int t;
cin>>t;
getchar();
for(int i=1;i<=t;i++){
    map<char,int>m;
    string s;
    getline(cin,s);
    for(int j=0;j<s.size();j++){
        if(s[j]>='A' && s[j]<='Z')
            s[j]=tolower(s[j]);
        m[s[j]]++;
    }
    //cout<<"case "<<endl;
    vector<pair<char,int> >v;
    map<char,int>::const_iterator it;
    it=m.begin();
    while(it!=m.end()){

        if(it->first<='z' && it->first>='a' || it->first>='A' && it->first<='Z')
            v.push_back({it->first,it->second});
        it++;
    }
    sort(v.begin(),v.end(),comp);
    int j=0;
    while(v[j].second==v[0].second){
        //if(v[j].first<='z' && v[j].first>='a' || v[j].first>='A' && v[j].first<='Z')
            cout<<v[j].first;
        j++;
    }
    cout<<endl;
}

return 0;
}
