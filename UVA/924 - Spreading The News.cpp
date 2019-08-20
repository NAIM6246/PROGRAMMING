#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n>0)
    {
        vector<int>v[n];
        int a,b;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            for(int j=0; j<a; j++)
            {
                cin>>b;
                v[i].push_back(b);
            }
        }
        int t;
        cin>>t;
        for(int i=0; i<t; i++)
        {
            cin>>a;
            queue<int>q;
            bool visited[n];
            memset(visited,0,sizeof(visited));
            visited[a]=1;
            for(int j=0; j<v[a].size(); j++)
            {
                q.push(v[a][j]);
                visited[v[a][j]]=1;
            }
            if(q.size()==0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                int boro=0,d=1,day=1;
                while(!q.empty())
                {
                    int si = q.size();
                    if(boro<si)
                    {
                        boro=si;
                        day=d;
                    }
                    while(si--)
                    {
                        for(int k=0; k<v[q.front()].size(); k++)
                        {
                            if(!visited[v[q.front()][k]])
                            {
                                q.push(v[q.front()][k]);
                                visited[v[q.front()][k]]=1;
                            }
                        }
                        q.pop();
                    }
                    d++;
                }
                cout<<boro<<" "<<day<<endl;
            }
        }
    }
    return 0;
}
