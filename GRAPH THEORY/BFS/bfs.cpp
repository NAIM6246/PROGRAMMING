#include<bits/stdc++.h>
using namespace std;
int main(){
int vertices,edges;
cin>>vertices>>edges;
vector<int >sam;
vector<vector<int> > connection(vertices+1,sam);
for(int i=0;i<edges;i++){
    int a,b;
    cin>>a>>b;
    connection[a].push_back(b);
    connection[b].push_back(a);
}
bool visited[vertices+1];
for(int i=0;i<vertices+1;i++)
    visited[i]=false;
int w;
cout<<"Starting Node"<<endl;
cin>>w;
visited[w]=true;
queue<int >level;
level.push(w);
    int si,le=0;
while(!level.empty()){
    cout<<"level : "<<le<<endl;
    si=level.size();
    while(si--){
        int x=level.front();
        cout<<x<<endl;
        level.pop();
        for(int i=0;i<connection[x].size();i++)
        {
            if(!visited[connection[x][i]])
            {
                visited[connection[x][i]]=true;
                level.push(connection[x][i]);
            }
        }
    }le++;
}
return 0;
}
