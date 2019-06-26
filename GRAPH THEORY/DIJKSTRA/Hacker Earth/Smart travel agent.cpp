#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define sze 1000009
#define sz 1005
#define INF 0x3f3f3f3f
vector<int >adj[sze];
vector<long long >cost[sze];
long long dist[105];
int val[105];
int parent[105];
typedef pair<int,int >Pair;
void Dijkstra(int start,int node)
{
    for(int i=0; i<=node; i++)
    {
        parent[i]=-1;
        val[i]=0;
    }

    parent[start]=start;
    val[start]=INT_MAX;
    priority_queue< Pair >Q;
    Q.push({val[start],start});
    int path_er_choto ,sb_cheye_boro=0;
    while(!Q.empty()){
//        Q.
        int a = Q.top().first;
        int b = Q.top().second;
        Q.pop();
        for(int i=0;i<adj[b].size();i++){
            int c = adj[b][i];
            int d = cost[b][i];
            if( val[c] < min(a,d) ){
                val[c] = min(a,d);
                Q.push({val[c],c});
                parent[c] = b;
            }
        }
    }
}


int main()
{
    int k,node,edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        int node1,node2,pa;
        long long c;
        cin>>node1>>node2>>pa;
        adj[node1].push_back(node2);
        cost[node1].push_back(pa);
        adj[node2].push_back(node1);
        cost[node2].push_back(pa);
    }
    int start,stop,total;
    cin>>start>>stop>>total;
    Dijkstra(start,node);
    int m = val[stop],ans1=0;
    if(total % (m-1) ==0){
        ans1 =  total/(m-1);
    }
    else{
        ans1 = total / (m-1) + 1;
    }

    int y = stop;
    vector<int> ans;
    ans.push_back(y);
    while(1)
    {
        int x = parent[y];
        ans.push_back(x);
        if( x == start )
        {
            break;
        }
        y=x;
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl<<ans1<<endl;

    return 0;
}
