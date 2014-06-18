#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
const int NN=300;  
const int MM=200000;  
const int INF=0x3fffffff;  
  
int n,m,S,T,NV,en,head[NN],hash[NN];  
struct Edge  
{  
    int u,v,flow,next;  
} e[MM];  
void add(int u,int v,int flow)  
{  
    e[en].u=u;  
    e[en].v=v;  
    e[en].flow=flow;  
    e[en].next=head[u];  
    head[u]=en++;  
    e[en].u=v;  
    e[en].v=u;  
    e[en].flow=0;  
    e[en].next=head[v];  
    head[v]=en++;  
}  
  
int dis[NN],pre[NN],gap[NN],cur[NN];  
int sap()  
{  
    int maxflow=0;  
    for (int i=0; i<NV; i++)  
    {  
        dis[i]=gap[i]=0;  
        cur[i]=head[i];  
    }  
    int aug=INF;  
    int u=pre[S]=S;  
    gap[0]=NV;  
    while (dis[S]<NV)  
    {  
        loop:  
        for (int &i=cur[u]; i!=-1; i=e[i].next)  
        {  
            int v=e[i].v;  
            if (e[i].flow && dis[u]==dis[v]+1)  
            {  
                if (e[i].flow<aug) aug=e[i].flow;  
                pre[v]=u;  
                u=v;  
                if (v==T)  
                {  
                    maxflow+=aug;  
                    for (u=pre[u]; v!=S; v=u,u=pre[u])  
                    {  
                        e[cur[u]].flow-=aug;  
                        e[cur[u]^1].flow+=aug;  
                    }  
                    aug=INF;  
                }  
                goto loop;  
            }  
        }  
        int min_dis=NV;  
        for (int i=head[u]; i!=-1; i=e[i].next)  
        {  
            int v=e[i].v;  
            if (e[i].flow && dis[v]<min_dis)  
            {  
                min_dis=dis[v];  
                cur[u]=i;  
            }  
        }  
        if (--gap[dis[u]]==0) break;  
        gap[dis[u]=min_dis+1]++;  
        u=pre[u];  
    }  
    return maxflow;  
}  
  
int w[MM],l[MM];  
bool solve()  
{  
    sap();  
    for (int i=head[S]; i!=-1; i=e[i].next) if (e[i].flow) return false;  
  
    printf("YES\n");  
    for (int i=0; i<m; i++) printf("%d\n",e[i*2+1].flow+l[i]);  
    return true;  
}  
  
int main()  
{  
    int u,v,c,sum;  
  
    en=0;  
    memset(w,0,sizeof(w));  
    memset(head,-1,sizeof(head));  
  
    scanf("%d%d",&n,&m);  
    S=0; T=n+1;  NV=T+1; sum=0;  
    for (int i=0; i<m; i++)  
    {  
        scanf("%d%d%d%d",&u,&v,&l[i],&c);  
        add(u,v,c-l[i]);  
        w[u]-=l[i];  
        w[v]+=l[i];  
    }  
    for (int i=1; i<=n; i++)  
    {  
        if (w[i]>0) add(S,i,w[i]);  
        if (w[i]<0) add(i,T,-w[i]);  
    }  
    if (!solve()) printf("NO\n");  
    return 0;  
} 