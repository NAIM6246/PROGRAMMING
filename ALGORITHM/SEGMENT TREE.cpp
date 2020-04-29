#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int tree[mx*3];
void buildTree(int node,int start,int stop,int a[]){
    if(start==stop){
        tree[node] = a[start];
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid= (start+stop)/2;
    buildTree(left,start,mid,a);
    buildTree(right,mid+1,stop,a);
    tree[node] = tree[left] + tree[right];
    return;
}

int query(int node, int start, int stop, int i, int j, int a[] ){
    if(i>stop || j<start)
        return 0;
    if(start>=i && stop <=j)
        return tree[node];
    int left = 2*node;
    int right = 2*node+1;
    int mid = (start+stop)/2;
    int l_side = query(left,start,mid,i,j,a);
    int r_side = query(right,mid+1,stop,i,j,a);
    return l_side + r_side;
}

void update(int node,int start, int stop, int pos, int val,int a[]){
    if(start > pos || stop < pos)
        return;
    if(start>=pos && stop <= pos)
    {
        tree[node] = val;
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (start+stop)/2;
    if(pos<=mid)
    update(left,start,mid,pos,val,a);
    else
    update(right,mid+1,stop,pos,val,a);
    tree[node] = tree[left]+tree[right];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    buildTree(1,0,n-1,a);
    ///(starting node, range of array [l,r], range of query [l,r])
    int x,y;
    cout<<"Enter the range of query : ";
    cin>>x>>y;
    cout<<query(1,0,n-1,x-1,y-1,a)<<endl;
    cout<<"enter where to update : ";
    int pos;
    cin>>pos;
    cout<<"Value : ";
    int val;
    cin>>val;
    update(1,0,n-1,pos-1,val,a);
    cout<<"Enter the range of query : ";
    cin>>x>>y;
    cout<<query(1,0,n-1,x-1,y-1,a)<<endl;
    return 0;
}
