#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>


#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))

#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define DOW0(i,x) for(i=x;i>=0;i--)
#define DOW1(i,x) for(i=x;i>=1;i--)
#define DOW(i,a,b) for(i=a;i>=b;i--)
using namespace std;


void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%I64d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%I64d%I64d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%I64d%I64d%I64d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}


void PR(int x) {printf("%d\n",x);}
void PR(i64 x) {printf("%I64d\n",x);}
void PR(u32 x) {printf("%u\n",x);}
void PR(double x) {printf("%.4lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}


const int N=10005;
stack<int> st;
vector<int> G[N];
int a[N][2],n,B,color[N],num,s[N];

void DFS(int u,int pre)
{
    st.push(u);
    int i,v,temp=0;
    FOR0(i,SZ(G[u]))
    {
        v=G[u][i];
        if(v==pre) continue;
        DFS(v,u);
        temp+=s[v];
        if(temp<B) continue;
        num++;
        a[num][0]=u;
        a[num][1]=temp;
        while(st.top()!=u)
        {
            color[st.top()]=num;
            st.pop();
        }
        temp=0;
    }
    s[u]=1+temp;
}

void print()
{
    if(n<B)
    {
        puts("0");
        return;
    }
    int i,j,k;
    if(n<=3*B)
    {
        puts("1");
        FOR1(i,n) printf("%d ",1);
        puts("1");
        return;
    }
    FOR1(i,n) if(!color[i])
    {
        a[num][1]++;
        color[i]=num;
    }
    FOR1(i,num) if(a[i][1]<B||a[i][1]>3*B)
    {
        puts("0");
        return;
    }
    PR(num);
    FOR1(i,n) printf("%d ",color[i]);puts("");
    FOR1(i,num) printf("%d ",a[i][0]);
    puts("");
}

int main()
{
    RD(n,B);
    int i,u,v;
    FOR1(i,n-1)
    {
        RD(u,v);
        G[u].pb(v);
        G[v].pb(u);
    }
    DFS(1,-1);
    print();
    return 0;
}