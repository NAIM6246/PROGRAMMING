#include<bits/stdc++.h>
using namespace std;
#define SZ INT_MAX
int main()
{
    int vertices,edges,ttl,sz=100,temp,temp2=0,test=1;
    while(1)
    {
        cin>>edges;
        if(edges==0)break;
        vector<int >ans;
        set<int>s;
        vector<int>connection[100000];
        for(int i=0; i<edges; i++)
        {
            int a,b;
            cin>>a>>b;
            s.insert(a);
            s.insert(b);
            connection[a].push_back(b);
            connection[b].push_back(a);
            temp=max(a,b);
            temp2=max(temp,temp2);
        }
        bool visited[temp2+1];
        for(int i=0; i<temp2+1; i++)
            visited[i]=false;
        int w;
        while(1){
        memset(visited,0,sizeof(visited));
        cin>>w>>ttl;
        if(w==0 && ttl==0)break;
        visited[w]=true;
        queue<int >level;
        level.push(w);
        int si=1,le=0,pq=0,counts=1;
        vector<int>ans;
        while(!level.empty())
        {
            si=level.size();
            while(si--)
            {
                int x=level.front();
                //cout<<x<<endl;
                //s.erase(x);
                ans.push_back(x);
                level.pop();
                for(int i=0; i<connection[x].size(); i++)
                {
                    if(!visited[connection[x][i]])
                    {
                        visited[connection[x][i]]=true;
                        level.push(connection[x][i]);
                    }
                }
            }
            le++;

            if(le==(ttl+1))
                break;
        }
        int dif=s.size()-ans.size();
        cout<<"Case "<<test<<": "<<dif<<" nodes not reachable from node "<<w<<" with TTL = "<<ttl<<"."<<endl;
        test++;
        //cout<<"size of s "<<s.size()<<" size of ans "<<ans.size()<<endl;
        ans.clear();
        }
    }
    return 0;
}
