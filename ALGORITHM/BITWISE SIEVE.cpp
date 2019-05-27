#include<bits/stdc++.h>
using namespace std;
///to check whether prime or not
bool check(int n, int pos){
    return
        (bool)(n & (1<<pos));
}
///to set value of non prime numbers
int Set(int n, int pos){
    return (n | (1<<pos));
}
void BitWiseSieve(long long n){
    int prime[(n>>5)+2];///vag dara binary te dane shift kora bujay..as 2^5=32 5 ghor dane shift hoise
    memset(prime,0,sizeof(prime));
    for(int i=3;i*i<=n;i+=2){
        if(check(prime[i>>5],i&31)==0){
            for(int j = i*i ; j<=n ; j += (i<<1)){///gun bare bame shift bujay
                prime[j>>5] = Set(prime[j>>5],j&31);
            }
        }
    }
    printf("2\n");
    for(int i=3;i<=n;i+=2)
        if(check(prime[i>>5],i&31)==0)
            cout<<i<<endl;
}
int main(){
    long long n;
    cin>>n;
    BitWiseSieve(n);
return 0;
}
