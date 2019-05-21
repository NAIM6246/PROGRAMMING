#include<bits/stdc++.h>
using namespace std;
struct Point{
    double x,y;
};
stack<Point>S;
Point p0;
Point nextToTop(stack<Point>S){
    Point p=S.top();
    S.pop();
    Point q=S.top();
    S.push(p);
    return q;
}



void swap_(Point &p1,Point &p2){
    Point t=p1;
    p1 = p2;
    p2 = t;
}


double distSq(Point p, Point q){

    return( (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y) );
}


int orientation(Point p, Point q, Point r){

    double slope=(q.y-p.y)*(q.x-r.x)-(q.y-r.y)*(q.x-p.x);
    if(slope==0)
        return 0;
    else if(slope>0)
        return 1;
    else return 2;
}
int compare(const void *vp1,const void *vp2){
    Point *p1=(Point *)vp1;
    Point *p2=(Point *)vp2;
    int o= orientation(p0,*p1,*p2);
    if(o==0){
        if((distSq(p0, *p2) >= distSq(p0, *p1)))
            return -1;
        else return 1;
    }
    else if(o==2)
        return -1;
    else return 1;
}
void convex_hull(Point points[],double n){
    int ymin=points[0].y,min_=0;
    for(int i=1;i<n;i++){
        double y = points[i].y;
        if(y<ymin || (y==ymin && points[i].x<points[min_].x))
            ymin=y,min_=i;
    }
    swap(points[0],points[min_]);
    p0= points[0];
    qsort(&points[1],n-1,sizeof(Point),compare);

    int m=1;
    for(int i=1;i<n;i++){
        while( i < n-1 && orientation(p0,points[i],points[i+1])==0 )
            i++;
        points[m]=points[i];
        m++;
    }
    if(m<3)
        return;
    S.push(points[0]);
    S.push(points[1]);
   // S.push(points[2]);
    for(int i=2;i<m;i++){
        while( orientation(nextToTop(S),S.top(),points[i])!=2 )
            S.pop();
        S.push(points[i]);
    }
    while(!S.empty()){
        Point x=S.top();
        cout<<"( "<<x.x<<" , "<<x.y<<" )"<<endl;
        S.pop();
    }

}


int main(){
    Point points[]={{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    double n = sizeof(points)/sizeof(points[0]);
    convex_hull(points,n);
return 0;
}
