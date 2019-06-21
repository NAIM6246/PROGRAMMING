#include<bits/stdc++.h>
using namespace std;
#define sz 1000
#define sze 1000000
#define IN 1000000000
typedef pair<int ,int>Pair;
typedef pair<int ,Pair>TII;
string adj[sz];
bool visited[sz][sz];
int distant[sz][sz];
int cost[sz][sz];
    int n,m,q;
    int fx[]={-1,1,0,0};
    int fy[]={0,0,-1,1};
void Dijkstra(int si,int sj);
int main(){
    cin>>n>>m>>q;
    distant[n][m];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>adj[i];
        for(int j=0;j<m;j++){
            distant[i][j]=IN;
        }
    }
    int si,sj,start;
    cin>>si>>sj;
//    if(si>0)
//        start=(si-1)*m+sj-1;
//    else
//        start = sj-1;
        /*
    for(int i=0;i<m*n;i++){
        if(adj[i].size()>0){
            cout<<i<<" => "<<endl;
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }
    cout<<"hi"<<endl;*/
    Dijkstra(si-1,sj-1);
    for(int i=0;i<q;i++){
        int di,dj;
        cin>>di>>dj;
        long long c= (di-1)*m+dj-1;
        if(distant[di-1][dj-1]==IN)
            cout<<"-1"<<endl;
        else
            cout<<distant[di-1][dj-1]<<endl;
    }
return 0;
}


void Dijkstra(int si,int sj){
//    for(long long i=0;i<=n*m;i++)
//    {
//        visited[i]=0;
//    }
    distant[si][sj] = 0;
/*
    for(int i=0;i<m*n;i++){
        if(adj[i].size()>0){
            cout<<i<<" => "<<endl;
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }*/
    priority_queue< TII , vector<TII>,greater<TII> > Q;
    Q.push(make_pair(0,make_pair(si,sj)));
    while(!Q.empty()){
        TII p = Q.top();
        Q.pop();
        Pair x = p.second;
        int y = x.first,z=x.second;
        //if(visited[y][z]==0){
            for(int i=0 ; i<4 ; i++){
                //int v = adj[x][i];
                int a = y+fx[i], b = z+fy[i];
                if( a>=0&&a<n && b>=0&&b<m && 1+distant[y][z]<distant[a][b] && adj[a][b]!='*'){
                    distant[a][b] = 1+distant[y][z];
                    Q.push( {distant[a][b],{a,b}} );
                }
            }
        //}
    }
}
