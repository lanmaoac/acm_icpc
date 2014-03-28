#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;
const double eps=1e-10;
struct point
{
    double x,y;
    point(double x=0,double y=0):x(x),y(y) {}
};
point operator + (point a,point b){
   return point(a.x+b.x,a.y+b.y);
}
point operator - (point a,point b){
   return point(a.x-b.x,a.y-b.y);
}
point operator * (point a,double p){
   return point(a.x*p,a.y*p);
}
point operator / (point a,double p){
   return point(a.x/p,a.y/p);
}
bool operator < (const point &a,const point&b){
    return a.x<b.x||(a.x==b.x && a.y<b.y);
}
int sgn(double x){
    if(fabs(x) < eps) return 0;else return x<0?-1:1;
}
bool operator == (const point&a,point&b){
   return sgn(a.x-b.x) && sgn(b.x-a.y);
}
point read_point(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    return point(a,b);
}
double dot(point a,point b){
   return a.x*b.x+a.y*b.y;
}
double lenght(point a){
    return sqrt(dot(a,a));
}
double angle(point a,point b)
{
    return  acos(dot(a,b)/lenght(a)/lenght(b));
}
point rotate(point a,double p){
  return point(a.x*cos(p)-a.y*sin(p),a.x*sin(p)+a.y*cos(p));
}
double cross(point a,point b)
{
    return a.x*b.y-b.x*a.y;
}
point getintersection(point a,point b,point c,point d){
     point u=a-c;
     double t=cross(d,u)/cross(b,d);
     return a+b*t;
}
point getpoint(point a,point b,point c){
    point v1=c-b;
    double a1=angle(a-b,v1);
    v1=rotate(v1,a1/3);
    point v2=b-c;
    double a2=angle(a-c,v2);
    v2=rotate(v2,-a2/3);
    return getintersection(b,v1,c,v2);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--){
    point a,b,c;
    a=read_point();
    b=read_point();
    c=read_point();
    point d=getpoint(a,b,c);
    point e=getpoint(b,c,a);
    point f=getpoint(c,a,b);
    printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",d.x,d.y,e.x,e.y,f.x,f.y);
    }
    return 0;
}
