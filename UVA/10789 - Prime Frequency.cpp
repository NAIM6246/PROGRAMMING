#include<bits/stdc++.h>
using namespace std;

    long long prime[(2005>>5)+2];
bool check(long long n, long long pos){
    return
        (bool)(n & (1<<pos));
}
///to set value of non prime numbers
long long Set(long long n, long long pos){
    return (n | (1<<pos));
}
void BitWiseSieve(long long n){
///vag dara binary te dane shift kora bujay..as 2^5=32 5 ghor dane shift hoise
    memset(prime,0,sizeof(prime));
//    cout<<"hi"<<endl;
    for(long long i=3;i*i<=n;i+=2){
        if(check(prime[i>>5],i&31)==0){
            for(long long j = i*i ; j<=n ; j += (i<<1)){///gun bare bame shift bujay
                prime[j>>5] = Set(prime[j>>5],j&31);
            }
        }
    }
//    printf("2\n");
//    for(long long i=3,j=1;i<=n;i+=2)
//        if(check(prime[i>>5],i&31)==0)
//        {
//            j++;
//            if((j%100)==1)cout<<i<<endl;
//        }

}


int main(){
BitWiseSieve(2005);
int t;
cin>>t;
for(int i=1;i<=t;i++){
    map<char,int>m;
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++){
        m[s[j]]++;
    }
    cout<<"Case "<<i<<": ";
    vector<char>v;
    map<char,int>::const_iterator it;
    it=m.begin();
    while(it!=m.end()){
        //cout<<it->first<<" "<<it->second<<" "<<check(prime[(it->second)>>5],it->second&31)<<endl;
        if(it->second==2)
            v.push_back(it->first);

        else if(it->second>2 && it->second%2!=0 && check(prime[(it->second)>>5],it->second&31)==0)
        {
            v.push_back(it->first);
        }
        it++;
    }
    if(v.size()>0){
    sort(v.begin(),v.end());
    for(int j=0;j<v.size();j++)
    cout<<v[j];
    cout<<endl;
    }
    else{
        cout<<"empty"<<endl;
    }
}

return 0;
}
