#include<bits/stdc++.h>
using namespace std;

/*
input taken as string
*/
int main()
{
    int v,e;
    cin>>v>>e;
    string f[]= {"bf","of","ds","em","sp","dn"};
    vector<int>sam;
    vector<vector<int > >adj(v+1,sam);
    for(int i=0; i<e; i++)
    {
        int a,b;
        char c[100],d[100];
        scanf("%s %s",&c,&d);
        for(int j=0; j<6; j++)
            if(f[j]==c)
                a=j,cout<<a<<endl;;
        for(int j=0; j<6; j++)
            if(f[j]==d)
                b=j,cout<<b<<endl;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool visited[v+1];
    memset(visited,0,sizeof(visited));
    int in_degree[v+1];
    memset(in_degree,0,sizeof(in_degree));
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            in_degree[adj[i][j]]++;
        }
    }
    vector<int >sorted;
    queue<int>q;
    for(int i=0;i<v;i++)
        if(in_degree[i]==0){
            sorted.push_back(i);
            q.push(i);
        }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int p=0;p<adj[x].size();p++){
            if(visited[adj[x][p]]==0){
                in_degree[adj[x][p]]--;
                if(in_degree[adj[x][p]]==0)
                {
                    visited[adj[x][p]]=1;
                    q.push(adj[x][p]);
                    sorted.push_back(adj[x][p]);
                }
            }
        }
    }
    for(int i=0;i<sorted.size();i++)
        cout<<f[sorted[i]]<<" ";

    cout<<endl;
    return 0;
}
