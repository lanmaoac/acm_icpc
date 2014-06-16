#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
const int MAXN =300;
const int MAXM =2100;
const int INF  =1<<20;
int n,m;
int indoor[210];
int outdoor[210];
struct node
{
    int next,to,cap;
};
node edge[MAXM];
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
        edge[countedge].next=head[start];
        edge[countedge].to=end;
        edge[countedge].cap=cap;
        head[start]=countedge++;
}
int sap(const int& start,const int& end)
{
        int i;
        for(i=0; i<n+2; i++)curedge[i]=head[i];
        numh[0]=n+2;
        int u=start,curflow,neck,ret=0;
        while(h[start]<n+2)
        {
            if(u==end)
            {
                curflow=INF;
                for(i=start; i!=end; i=edge[curedge[i]].to)
                {
                    if(curflow>edge[curedge[i]].cap)
                    {
                        curflow=edge[curedge[i]].cap;
                        neck=i;
                    }
                }
                for(i=start; i!=end; i=edge[curedge[i]].to)
                {
                    int e=curedge[i];
                    edge[e].cap-=curflow;
                    edge[e^1].cap+=curflow;
                }
                ret+=curflow;
                u=neck;
            }
            for(i=curedge[u]; i!=-1; i=edge[i].next)
            {
                if(edge[i].cap&&h[edge[i].to]+1==h[u])break;
            }
            if(i!=-1)
            {
                curedge[u]=i;
                pre[edge[i].to]=u;
                u=edge[i].to;
            }
            else
            {
                if(0==--numh[h[u]])break;
                curedge[u]=head[u];
                int H=n+2;
                for(i=head[u]; i!=-1; i=edge[i].next)
                {
                    if(edge[i].cap)H=min(H,h[edge[i].to]+1);
                }
                h[u]=H;
                numh[H]++;
                if(u!=start)u=pre[u];
            }
        }
        return ret;
}
int main()
{
  int cas;
  scanf("%d",&cas);
  while(cas--)
  {
    scanf("%d%d",&n,&m);
    init();
    memset(indoor,0,sizeof(indoor));
    memset(outdoor,0,sizeof(outdoor));
    for(int i=1;i<=m;i++)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      indoor[b]++;
      outdoor[a]++;
      if(c==0)
      {
          addedge(a,b,1);
          addedge(b,a,0);
      }
    }
    bool flag=true;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
      if((indoor[i]-outdoor[i])%2==1)
      {
        flag=false;
        break;
      }
      int k=indoor[i]-outdoor[i];
      if(k>0) {addedge(i,n+1,k/2);sum+=k/2;addedge(n+1,i,0);}
      else  {addedge(0,i,-k/2);addedge(i,0,0);}
    }
    if(!flag)  {printf("impossible\n");continue;}
    if(sap(0,n+1)!=sum) flag=false;
    if(!flag)  printf("impossible\n");
    else printf("possible\n");
  }
  return 0;
}
