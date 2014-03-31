#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#define eps 1e-9
#define maxn 10009
using namespace std;
double  high,bis,med;

struct point
{
    double x,y;
    point(double x=0,double y=0):x(x),y(y) {}
};
point a,b,c;
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
double len(point a){
    return sqrt(dot(a,a));
}
double angle(point a,point b)
{
    return  acos(dot(a,b)/len(a)/len(b));
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
bool judge()
{
  int a=sgn(bis-high);
  int b=sgn(med-bis);
  if(a<0 || b<0) return 1;
  if(a==0&&b!=0) return 1;
  if(a!=0&&b==0) return 1;
  return 0;
}
double cal(double now)
{
    b=point(0,0);
    c=point(now,0);
    a.x=now/2.0+sqrt(med*med-high*high);
    a.y=high;
    double ab,ac,bc;
    ab=len(a-b);
    ac=len(a-c);
    double t=ab/(ab+ac);
    point d=(c-b)*t+b;
    double ad=len(a-d);
    return ad;
}
int main()
{

    scanf("%lf %lf %lf",&high,&bis,&med);
    if(judge()) {printf("NO\n");return 0;}
    double r=1e5;
    double l=0;double mid;
    while(r-l>1e-9){
       mid=(l+r)/2.0;
       double ans=cal(mid);
       if(sgn(ans-bis)==0) break;
       else if(sgn(ans-bis)>0) l=mid;
            else r=mid;
    }
    mid=(l+r)/2.0;
    cal(mid);
    printf("YES\n");
    printf("%.7lf %.7lf\n",a.x,a.y);
    printf("%.7lf %.7lf\n",b.x,b.y);
    printf("%.7lf %.7lf\n",c.x,c.y);
    return 0;
}