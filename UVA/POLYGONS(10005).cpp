#include<bits/stdc++.h>
using namespace std;
struct Point{
    double x,y;
};
double distSquare(Point p,Point q){
    return ( (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y) );
}
bool circle2PtsRad(Point p1,Point p2,double r,Point &c){

    double d2 = ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y );
    double det = (r*r)/d2 - 0.25;
    if(det<0.0)return false;
    double h = sqrt(det);
    ///centre of the circle
    c.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
    c.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
    return true;
}
bool check(Point a,Point b,double r){

    if(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))<=r)
        return true;
    else
        return false;
}

int main()
{
    long t;
    while(cin>>t && t!=0){
        Point points[t];
        for(int i=0;i<t;i++){
            cin>>points[i].x>>points[i].y;
        }
        double R;
        cin>>R;
        bool flag=0;
        for(int i=0;i<t-1;i++){
            for(int j=i+1;j<t;j++){
                Point c;
                if(circle2PtsRad(points[i],points[j],R,c)){
                    int n=0;
                    for(int k=0;k<t;k++){
                        n+=check(c,points[k],R);
                    }
                    if(n==t)
                    {
                        flag=1;
                        break;
                    }
                }
                if(circle2PtsRad(points[j],points[i],R,c)){
                    int n=0;
                    for(int k=0;k<t;k++){
                        n+=check(c,points[k],R);
                    }
                    if(n==t)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(flag)
            printf("The polygon can be packed in the circle.\n");
        else
            printf("There is no way of packing that polygon.\n");
    }
    return 0;
}
