#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
#define sz 1000000
#define inf 1000000000
typedef pair<int,int> pii;

vector <int> adj[sz];
long long cost[1000][1000];
int distant[sz];
int parent[sz];
bool visited[sz];

void dijkstra(int startingNode);

int main() {
    int t;
//    freopen("input1.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
    cin >> n >> m;

    int node1,node2,dis;
    for ( int i = 0 ; i < n ; i++) {
            for(long long j=0;j<m;j++){
                cin>>dis;
                int pos1=i*m+j,pos2=(i-1)*m+j;
                cost[i][j]=dis;
                if(i==0 && j==0){
                    adj[0].push_back(0);
                }
                else if(i==0 && j>0){
                    adj[pos1-1].push_back(pos1);
                    adj[pos1].push_back(pos1-1);
                }
                else if(i>0 && j==0){

                    adj[pos2].push_back(pos1);

                    adj[pos1].push_back(pos2);
                }
                else if(i>0 && j>0){

                    adj[pos2].push_back(pos1);

                    adj[pos1].push_back(pos2);

                    adj[pos1-1].push_back(pos1);

                    adj[pos1].push_back(pos1-1);
                }
            }

    }
   dijkstra(0);
   cout<<distant[m*n-1]<<endl;
    for(int i=0;i<=m*n;i++)
        adj[i].clear();
    }
   return 0 ;
}

void dijkstra(int startingNode) {
    for ( long long i = 0 ; i <= n*m ; i++ ) {
            distant[i] = inf;
            visited[i] = false;
    }
    distant[startingNode] = cost[startingNode][startingNode];
    visited[startingNode] = false;
    priority_queue < pii , vector<pii> , greater <pii> > Q ;
    Q.push(make_pair(distant[startingNode],startingNode));
    while( !Q.empty()) {
        pii p = Q.top();
        Q.pop();
        int v = p.second;///current node
        if ( visited[v] == false) {
            for ( int i = 0 ; i < adj[v].size() ; i++) {
                int pq = adj[v][i];///next node to visit
                int g=pq/m , h = pq%m;
                if ( cost[g][h]+distant[v] < distant[pq]) {
                    distant[pq] = cost[g][h]+distant[v];
                    parent[pq] = v ;
                    Q.push(make_pair(distant[pq],pq));
                }
            }
        }
        visited[v] = true;
    }
}
