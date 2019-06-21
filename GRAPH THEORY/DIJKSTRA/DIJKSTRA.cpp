#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
vector< pair<int,int> >v[5000];///v[from] => pair< to,distance >
vector<int >dist(1000,INF);
bool visited[5000];

void Dijkstra(int start){
    memset(visited,0,sizeof(visited));
    dist[start]=0;
    priority_queue< ipair, vector<ipair> , greater<ipair> >p;
    p.push({0,start});
    while(!p.empty()){
        ipair x = p.top();
        p.pop();
        int a =x.first,b=x.second ;///a => weight of that node, b=>that node
        if(visited[b])
            continue;
        visited[b]=1;
        for(int i=0; i<v[b].size();i++){
            int vert = v[b][i].first, wei = v[b][i].second;
            if( dist[b]+wei < dist[vert]){
                dist[vert] = dist[b]+wei;
                p.push({dist[vert],vert});

            }

        }
    }
}

int main(){
    int n,from,to,dis,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>from>>to>>dis;
        v[from].push_back(make_pair(to,dis));
        v[to].push_back(make_pair(from,dis));
    }
    int start;
    cin>>start;
    Dijkstra(start);
    for(int i=0;i<n;i++){
        cout<<"Node : "<<i<<" Cost : "<<dist[i]<<endl;
    }
return 0;
}
