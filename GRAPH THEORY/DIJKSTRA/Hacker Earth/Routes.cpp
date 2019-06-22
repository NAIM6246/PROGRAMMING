#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define sze 1000009
#define sz 1005
#define INF 0x3f3f3f3f
vector<int >adj[sze];
vector<long long >cost[sze];
long long dist[sz+5];
bool visited[sze];
int Time[sz+5][sz+5];
int parent[sz+5];
typedef pair<long long,int >Pair;

void Dijkstra(int start,int node,int stop,int k)
{
    memset(visited,0,sizeof(visited));
    for(int i=0; i<=node; i++)
    {
        parent[i]=-1;
        dist[i]=INF;
    }
    visited[start]=0;
    parent[start]=start;
    dist[start]=0;
    priority_queue< Pair, vector<Pair>,greater<Pair> >Q;
    Q.push(make_pair(dist[start],start));
    while(!Q.empty())
    {
        Pair p = Q.top();
        Q.pop();
        int a = p.second;///current node
        if(!visited[a])
        {
            for(int i=0; i<adj[a].size(); i++)
            {
                int b = adj[a][i];///next node to visit
                if( dist[a] + cost[a][i] + k <dist[b] && a!=start )
                {
                    dist[b] = dist[a] + cost[a][i] + k;
                    Q.push(make_pair(dist[b],b));
                    parent[b]=a;
                }
                else if( dist[a] + cost[a][i]  <dist[b] && a==start ){
                    dist[b] = dist[a] + cost[a][i] ;
                    Q.push(make_pair(dist[b],b));
                    parent[b]=a;
                }
            }
        }
        visited[a]=1;
    }
}


int main()
{
    int k,node,edge;
    cin>>k>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        int node1,node2,ti,co;
        long long c;
        cin>>node1>>node2>>ti>>co;
        c = co+(ti*k);
        Time[node1][node2]=ti;
        Time[node2][node1]=ti;
        adj[node1].push_back(node2);
        cost[node1].push_back(c);
        adj[node2].push_back(node1);
        cost[node2].push_back(c);
    }
    int start,stop;
    cin>>start>>stop;
    Dijkstra(start,node,stop,k);
    long long major = dist[stop];
    long long c = ((node-1)*node)/2;
    if(major == INF || edge>c)
        cout<<"Error"<<endl;
    else{
    long long layover = 0, t=0;
    int y = stop;
    string ans="",s;
    s = to_string(stop);
    ans+=(s+">-");
    while(1)
    {
        int x = parent[y];
        s = to_string(x);
        t+=Time[x][y];
        ans+=(s);
        if( x == start )
        {
            break;
        }
        //layover += k;
        t++;
        ans+=">-";
        y=x;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<" "<<t<<" "<<major+layover<<endl;
    }
    return 0;
}
