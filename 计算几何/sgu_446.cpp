#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const double pi=3.1415926535897932384626;
inline int sgn(double a)
{
    if(fabs(a)<1e-5)
        return 0;
    if(a<0)
        return -1;
    return 1;
}

struct point
{
    double x,y,ang,dis;
    friend point operator - (point a,point b)
    {
        return (point){a.x-b.x,a.y-b.y};
    }
    friend point operator + (point a,point b)
    {
        return (point){a.x+b.x,a.y+b.y};
    }
    friend double operator / (point a,point b)
    {
        return a.x*b.y-a.y*b.x;
    }
    friend double dist(point a,point b)
    {
        point c=a-b;
        return sqrt(c.x*c.x+c.y*c.y);
    }
}p1[1001],p2[1001],p2_px[1001];
point base_p,base_p2;
double base_ang;
inline double get_ang(point base_p,double base_ang,point a)
{
    double now_ang=atan2(a.y-base_p.y,a.x-base_p.x)-base_ang;
    if(sgn(now_ang-pi)>0)
        now_ang-=pi*2;
    if(sgn(now_ang+pi)<=0)
        now_ang+=pi*2;
    return now_ang;
}
void init(point *l,point *r)
{
    for(;l<r;++l)
    {
        l->ang=get_ang(base_p,base_ang,*l);
        l->dis=dist(*l,base_p);
    }
}
inline bool operator < (point a,point b)
{
    if(sgn(a.ang-b.ang)==0)
        return a.dis-b.dis<0;
    return a.ang-b.ang<0;
}
int main()
{
    int i,j,k,n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    if(n<=1)
    {
        printf("0\n");
        return 0;
    }
    for(i=0;i<n;++i)
        scanf("%lf%lf",&p1[i].x,&p1[i].y);
    for(i=0;i<n;++i)
        scanf("%lf%lf",&p2[i].x,&p2[i].y);
    int mini,minj;
    double mind=1e+30;
    for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
        {
            double now=dist(p1[i],p1[j]);
            if(now<mind)
            {
                mind=now;
                mini=i;
                minj=j;
            }
        }
    
    swap(p1[0],p1[mini]);
    swap(p1[1],p1[minj]);
    base_p=p1[0];
    base_p2=p1[1];
    base_ang=atan2(base_p2.y-base_p.y,base_p2.x-base_p.x);
    init(p1+2,p1+n);
    sort(p1+2,p1+n);
    
    double std_ang=base_ang,ans=10;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            if(sgn(dist(p2[i],p2[j])-mind)==0)
            {
                for(k=0;k<n;++k)
                    p2_px[k]=p2[k];
                swap(p2_px[0],p2_px[i]);
                if(j)
                    swap(p2_px[1],p2_px[j]);
                else
                    swap(p2_px[1],p2_px[i]);
                base_p=p2_px[0];
                base_p2=p2_px[1];
                base_ang=atan2(base_p2.y-base_p.y,base_p2.x-base_p.x);
                init(p2_px+2,p2_px+n);
                sort(p2_px+2,p2_px+n);
                for(k=2;k<n;++k)
                    if(sgn(get_ang(base_p,base_ang,p2_px[k])-get_ang(p1[0],std_ang,p1[k])))
                        break;
                if(k>=n)
                {
                    double now=base_ang-std_ang;
                    if(sgn(now-pi)>0)
                        now-=pi*2;
                    if(sgn(now+pi)<=0)
                        now+=pi*2;
                    if(sgn(now)<0)
                        now=-now;
                    if(now<ans)
                        ans=now;
                }
            }
    
    printf("%.10lf\n",ans+1e-12);
    return 0;
}