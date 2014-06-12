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
struct Edge
{
    int next,to,cap;
};
struct F
{
    Edge edge[MAXM];
    int head[MAXN],countedge;
    int h[MAXN],numh[MAXN],curedge[MAXN],pre[MAXN];
    int N;
    void Init(int N)
    {
        this->N=N;
        memset(head,-1,sizeof(head));
        countedge=0;
        memset(numh,0,sizeof(numh));
        memset(h,0,sizeof(h));
        memset(pre,-1,sizeof(pre));
    }
    void AddEdge(const int& start,const int& end,const int& cap)
    {
        edge[countedge].next=head[start];
        edge[countedge].to=end;
        edge[countedge].cap=cap;
        head[start]=countedge++;
    }

    int SAP(const int& start,const int& end)
    {
        int i;
        for(i=0; i<N; i++)curedge[i]=head[i];
        numh[0]=N;
        int u=start,curflow,neck,ret=0;
        while(h[start]<N)
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
                int H=N;
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
};
int main()
{ 
  while(scanf("%d%d",&n,&m)!=0)
  { 
    F.Init(n);
     for(int i=1;i<=n;i++)
     {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      F.add(a,b,c);
      F.add(b,a,0);
     }
    printf("%d\n",F.SAP(1,m)); 
  }
  return 0;
}
