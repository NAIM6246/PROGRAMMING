#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);

    int n,e,white=0,red=1,blue=2;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d",&e);

        vector<int >sam;
        vector<vector<int> >conn(n+1,sam);
        int a,b,source=0;
        for(int i=0; i<e; i++)
        {
            scanf("%d %d",&a,&b);
            conn[a].push_back(b);
            conn[b].push_back(a);
        }
        queue<int>q;
        q.push(source);
        int color[n+1];
        memset(color,white,sizeof(color));
        int flag=0;
        while(!q.empty())
        {
            int x,y,v;
            x=q.size();
            while(x--)
            {
                y=q.front();
                q.pop();
                for(int i=0;i<conn[y].size();i++){
                    v=conn[y][i];
                    if(color[v]== white ){
                        if(color[y]==red)
                            color[v]=blue;
                        //cout<<color[y]<<" "<<color[v]<<" "<<y<<" "<<v<<endl;}
                        else color[v]=red;//cout<<color[y]<<" "<<color[v]<<"hi "<<y<<" "<<v<<endl;}
                        q.push(v);
                    }
                    if(color[y] == color[v])
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        scanf("%d",&n);
    }
    return 0;
}
