#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int N =200005;
struct node
{
   int to;
   int next;
   int w;
}edge[N*2];int head[N],top=0;
int f[N]={0};
int g[N]={0};
int n,m;
void add(int from,int to,int w)
{
    edge[top].to=to;
    edge[top].next=head[from];
    edge[top].w=w;
    head[from]=top++;
}
void dfs1(int now,int father)
{
	f[now]=0;
     for(int i=head[now];i!=-1;i=edge[i].next){
     	    int v=edge[i].to;
     	    if(v!=father){
     	    	f[now]+=edge[i].w;
     	    	dfs1(v,now);
     	    	f[now]+=f[v];
     	    	
     	    }
     }
}
void dfs2(int now,int father,int w)
{   if(father==-1)
	{
		g[now]=f[now];
	}
	else
	g[now]=g[father]-f[now]-w+(1-w);
    for(int k=head[now];k!=-1;k=edge[k].next)
    {
    	int v=edge[k].to;
    	if(v!=father){
           dfs2(v,now,edge[k].w);
       }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    for(int i=0;i<n-1;i++)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	add(a,b,0);
    	add(b,a,1);
    }
    dfs1(1,-1);
    dfs2(1,-1,0);
    int minn=0x7fffffff;
    int  id=0;
    for(int i=1;i<=n;i++)
    	printf("%d %d\n",f[i],g[i]);
    for(int i=1;i<=n;i++)
     if(minn>=g[i]){
     	minn=g[i];
     	id=i;
     }
     printf("%d\n",minn);

     for(int i=1;i<=n;i++)
     {
     	if(i==id)
     	{
     		printf("%d",i);
     		break;
     	}
     	if(g[i]==minn)
     		printf("%d ",i);
     }
    return 0;
}
