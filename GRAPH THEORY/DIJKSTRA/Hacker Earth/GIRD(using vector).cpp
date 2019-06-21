#include<bits/stdc++.h>
using namespace std;
#define sz 1005
#define sze 1000005
#define INF 1000000000
typedef pair<int ,int>Pair;
vector<int>adj[sze];
bool visited[sze];
int distant[sze];
int cost[sz][sz];
    int n,m,q;
void Dijkstra(int start,long long node);
int main(){
    cin>>n>>m>>q;
    cost[n][m];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++){//cout<<s<<endl;
            long long pos1=i*m+j , pos2 = (i-1)*m+j;
            if(s[j]=='O')
                cost[i][j]=1;
            else
                cost[i][j]=0;
            if(i==0 && j==0){
                adj[0].push_back(0);
            }
            else if(i==0 && j>0){
                if( s[j]=='O' && s[j-1]=='O' ){
                    adj[pos1-1].push_back(pos1);
                    adj[pos1].push_back(pos1-1);
                }
            }
            else if(i>0 && j==0){
                if( s[j]=='O' && cost[pos2/m][pos2%m]==1 )
                {
                    adj[pos2].push_back(pos1);
                    adj[pos1].push_back(pos2);
                }
            }
            else if(i>0 && j>0){
                if(s[j]=='O' && s[j-1]=='O'){
                    adj[pos1].push_back(pos1-1);
                    adj[pos1-1].push_back(pos1);
                }
                if( s[j]=='O' && cost[pos2/m][pos2%m]==1 ){
                    adj[pos2].push_back(pos1);
                    adj[pos1].push_back(pos2);
                }
            }
        }
    }
    int si,sj,start;
    cin>>si>>sj;
    if(si>0)
        start=(si-1)*m+sj-1;
    else
        start = sj-1;
    Dijkstra(start,m*n);
    for(int i=0;i<q;i++){
        int di,dj;
        cin>>di>>dj;
        long long c= (di-1)*m+dj-1;
        if(distant[c]==INF)
            cout<<"-1"<<endl;
        else
            cout<<distant[c]<<endl;
    }
return 0;
}

void Dijkstra(int start,long long node){
    memset(visited,0,sizeof(visited));
    for(long long i=0;i<=node;i++)
    {
        distant[i]=INF;
        visited[i]=0;
    }
    distant[start] = 0;
    visited[start] = 0;
    priority_queue< Pair , vector<Pair>,greater<Pair> > Q;
    Q.push(make_pair(0,start));
    while(!Q.empty()){
        Pair p = Q.top();
        Q.pop();
        int x = p.second;
        if(visited[x]==0){
            for(int i=0 ; i<adj[x].size() ; i++){
                int v = adj[x][i];
                int a = v/m, b = v%m;
                if(cost[a][b]+distant[x]<distant[v]){
                    distant[v] = cost[a][b]+distant[x];
                    Q.push(make_pair(distant[v],v));
                }
            }
        }
        visited[x]=1;
    }
}
