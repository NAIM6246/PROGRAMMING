#include <bits/stdc++.h>
using namespace std;
int vertex,edge;
#define sz 100000
#define inf 10000000
typedef pair<int,int> pii;

vector <int> adj[sz];
vector <int> cost[sz];
int distant[sz];
int parent[sz];
bool visited[sz];

void dijkstra(int startingNode);

int main() {
    cin >> vertex >> edge;
    int node1,node2,weight;
    for ( int i = 0 ; i < edge ; i++) {
        cin >> node1 >> node2 >> weight;
        adj[node1].push_back(node2);
        cost[node1].push_back(weight);
        adj[node2].push_back(node1);
        cost[node2].push_back(weight);
    }

   cout << "PLEASE ENTER YOUR STARTING NODE: " << endl;
   int startingNode;
   cin >> startingNode;
   dijkstra(startingNode);
   cout << "VERTEX\tCOST\tPARENT" << endl;
   for ( int i = 0 ; i < vertex ; i++) {
     cout << i << " \t" << distant[i] << "\t" << parent[i] << endl ;
   }
   cout << endl;
   return 0 ;
}

void dijkstra(int startingNode) {
    for ( int i = 0 ; i < vertex ; i++ ) {
        if ( i != startingNode) {
            distant[i] = inf;
            parent[i] = -1 ;
            visited[i] = false;
        }
    }
    distant[startingNode] = 0 ;
    parent[startingNode] = startingNode;
    visited[startingNode] = false;
    priority_queue < pii , vector<pii> , greater <pii> > Q ;
    Q.push(make_pair(distant[startingNode],startingNode));
    while( !Q.empty()) {
        pii p = Q.top();
        Q.pop();
        int v = p.second;
        if ( visited[v] == false) {
            for ( int i = 0 ; i < adj[v].size() ; i++) {
                int p = adj[v][i];
                if ( cost[v][i]+distant[v] < distant[p]) {
                    distant[p] = cost[v][i]+distant[v];
                    parent[p] = v ;
                    Q.push(make_pair(distant[p],p));
                }
            }
        }
        visited[v] = true;
    }
}
