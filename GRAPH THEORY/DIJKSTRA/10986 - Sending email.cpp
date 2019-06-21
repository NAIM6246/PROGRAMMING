#include<bits/stdc++.h>
using namespace std;
typedef pair<long long , long long >Pair;
#define INF 0x3f3f3f3f
vector<pair<long long , long long > >con[200009];
long long dist[200009];
bool visited[200009];

void Dijkstra(int start,int stop){
    memset(visited,0,sizeof(visited));
    for(long long i=0;i<200001;i++)
        dist[i]=INF;
    dist[start]=0;
    priority_queue<Pair,vector<Pair>,greater<Pair> >p;
    p.push(make_pair(0,start));
    while(!p.empty()){int qwe=0;
        Pair x = p.top();
        p.pop();
        long long b = x.second , a = x.first;
//        if(qwe==1)
//            return;
//        if(visited[b] && stop==b)
            return ;///qwe=1;
        if(visited[b])
            continue;
        visited[b]=true;
        for(long long i=0;i<con[b].size();i++){
            long long vert = con[b][i].first , wei = con[b][i].second;
            if(dist[b] + wei<dist[vert]){
                dist[vert]=dist[b]+wei;
                p.push(make_pair(dist[vert],vert));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int l=1;l<=t;l++){
        long long n,m,S,T;
        cin>>n>>m>>S>>T;
            long long from,to,dis;
        for(long long i=0;i<m;i++){
            cin>>from>>to>>dis;
            con[from].push_back(make_pair(to,dis));
            con[to].push_back(make_pair(from,dis));
        }
        long long ans;
        if(m>0)
            {Dijkstra(S,T);ans=dist[T];}
        else
            ans=INF;
        if(ans==INF)
            cout<<"Case #"<<l<<": "<<"unreachable"<<endl;
        else
            cout<<"Case #"<<l<<": "<<ans<<endl;
        for(int i=0;i<200001;i++){
            if(con[i].size()>0)
            con[i].clear();
        }

    }
return 0;
}
