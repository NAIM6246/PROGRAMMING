#include<bits/stdc++.h>
using namespace std;
int white = 0,grey =1,black=2;
int visited[100005];
void DFS(vector<int>g[],int u){
    visited[u] = grey;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(visited[v] == white){
            DFS(g,v);
        }
    }
    visited[u] = black;
    cout<<u<<endl;
    return;
}
int main(){
int n,e;
cin>>n>>e;
vector<int>Graph[n+5];
int from,to;
for(int i=0;i<e;i++){
    cin>>from>>to;
    Graph[from].push_back(to);
    Graph[to].push_back(from);
}
memset(visited,0,sizeof(visited));
int start;
cin>>start;
DFS(Graph,start);
return 0;
}
