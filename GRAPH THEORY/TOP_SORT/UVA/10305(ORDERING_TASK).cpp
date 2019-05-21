#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    while(1){
    cin>>v>>e;
    if(v==0 && e==0)break;
    vector<int>sam;
    vector<vector<int > >adj(v+1,sam);
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool visited[v+1];
    memset(visited,0,sizeof(visited));
    int in_degree[v+1];
    memset(in_degree,0,sizeof(in_degree));
    for(int i=0;i<=v;i++){
        for(int j=0;j<adj[i].size();j++){
            in_degree[adj[i][j]]++;
        }
    }
    vector<int >sorted;
    priority_queue<int ,vector<int>,greater<int> >q;
    for(int i=1;i<=v;i++)
        if(in_degree[i]==0){
            q.push(i);
            visited[i]=1;
        }
    while(!q.empty()){
        int x=q.top();
        q.pop();
        sorted.push_back(x);
        for(int p=0;p<adj[x].size();p++){
            if(visited[adj[x][p]]==0){
                in_degree[adj[x][p]]--;
                if(in_degree[adj[x][p]]==0)
                {
                    visited[adj[x][p]]=1;
                    q.push(adj[x][p]);
                }
            }
        }
    }
    for(int i=0;i<sorted.size()-1;i++)
    cout<<sorted[i]<<" ";
    cout<<sorted[sorted.size()-1];
    cout<<endl;
    sorted.clear();
    }
    return 0;
}
