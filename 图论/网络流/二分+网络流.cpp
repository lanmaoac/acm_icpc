#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
const int   INF = 1<<25;
const int  MAXN = 250;
const int  MAXM = 250*250*2+1000;
using namespace std;
int k,c,m;
int edge[250][250];
void floyd()
{
  for(int x=1;x<=k+c;x++)
    for(int i=1;i<=k+c;i++)
      for(int j=1;j<=k+c;j++)
          if(edge[i][j]>edge[i][x]+edge[x][j])
             edge[i][j]=edge[i][x]+edge[x][j];
}
struct node
{
    int next,to,cap;
};
node Edge[MAXM];
int head[MAXN],countedge;
int h[MAXN],numh[MAXN],curedge[MAXN],pre[MAXN];
void init()
{
        memset(head,-1,sizeof(head));
        countedge=0;
        memset(numh,0,sizeof(numh));
        memset(h,0,sizeof(h));
        memset(pre,-1,sizeof(pre));
}

void addedge(const int& start,const int& end,const int& cap)
{
        Edge[countedge].next=head[start];
        Edge[countedge].to=end;
        Edge[countedge].cap=cap;
        head[start]=countedge++;
}
int sap(const int& start,const int& end)
{
        int i;
        for(i=0; i<k+c+2; i++)curedge[i]=head[i];
        numh[0]=k+c+2;
        int u=start,curflow,neck,ret=0;
        while(h[start]<k+c+2)
        {
            if(u==end)
            {
                curflow=INF;
                for(i=start; i!=end; i=Edge[curedge[i]].to)
                {
                    if(curflow>Edge[curedge[i]].cap)
                    {
                        curflow=Edge[curedge[i]].cap;
                        neck=i;
                    }
                }
                for(i=start; i!=end; i=Edge[curedge[i]].to)
                {
                    int e=curedge[i];
                    Edge[e].cap-=curflow;
                    Edge[e^1].cap+=curflow;
                }
                ret+=curflow;
                u=neck;
            }
            for(i=curedge[u]; i!=-1; i=Edge[i].next)
            {
                if(Edge[i].cap&&h[Edge[i].to]+1==h[u])break;
            }
            if(i!=-1)
            {
                curedge[u]=i;
                pre[Edge[i].to]=u;
                u=Edge[i].to;
            }
            else
            {
                if(0==--numh[h[u]])break;
                curedge[u]=head[u];
                int H=k+c+2;
                for(i=head[u]; i!=-1; i=Edge[i].next)
                {
                    if(Edge[i].cap)H=min(H,h[Edge[i].to]+1);
                }
                h[u]=H;
                numh[H]++;
                if(u!=start)u=pre[u];
            }
        }
        return ret;
}
void build(int mid)
{
    init();
    for(int i=k+1;i<=k+c;i++)  {addedge(0,i,1);addedge(i,0,0);}
    for(int i=1;i<=k;i++) {addedge(i,k+c+1,m);addedge(k+c+1,i,0);}
    for(int i=k+1;i<=k+c;i++)
        for(int j=1;j<=k;j++)
            if(edge[i][j]<=mid) {addedge(i,j,1);addedge(j,i,0);}
}
bool check(int mid)
{
  build(mid);
  int ans=sap(0,k+c+1);
  if(ans==c) return true;
  else return false;
}
int gao()
{
    int l=0,r=20000;
    while(l<r)
    {
      int mid=(l+r)/2;
      if(check(mid))
        r=mid;
      else
        l=mid+1;
    }
    return r;
}
int main()
{
   while(scanf("%d%d%d",&k,&c,&m)!=EOF)
  {
   memset(edge,0,sizeof(edge));
   for(int i=1;i<=k+c;i++)
    for(int j=1;j<=k+c;j++)
      {
        scanf("%d",&edge[i][j]);
        if(!edge[i][j]) edge[i][j]=INF;
      }
   floyd();
   int ans=gao();
   printf("%d\n",ans);
  }
  return 0;
}
