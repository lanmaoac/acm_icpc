#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <map>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int to;
    int w;
    int next;
}edge[200100];
int head[100100],top;
bool po[100010];
int next[100010];
int dp[100010][5];
bool vis[100010];
void init()
{
	memset(head,-1,sizeof(head));
	memset(po,0,sizeof(po));
	memset(vis,0,sizeof(vis));
	top=0;
}
void add(int from,int to)
{
	edge[top].to=to;
	edge[top].next=head[from];
	head[from]=top++;
}
void dfs_1(int now,int father)
{
    dp[now][0]=dp[now][1]=-1;
    dp[now][2]=-1;
    next[now]=0;
    vis[now]=true;
    if(po[now]) dp[now][0]=0;
    for(int i=head[now];i!=-1;i=edge[i].next)
     {
      	int son=edge[i].to;
      	if(son==father) continue;
        dfs_1(son,now);
        if(dp[son][0]>=0)
        {
        	if(dp[son][0]+1>=dp[now][0])
        	{
        		dp[now][1]=dp[now][0];
        		dp[now][0]=dp[son][0]+1;
        		next[now]=son;
            }
            else
            {
            	dp[now][1]=max(dp[son][0]+1,dp[now][1]);
            }
        }
     }
}
void dfs_2(int now,int father)
{
   for(int i=head[now];i!=-1;i=edge[i].next)
   {
	   	int son=edge[i].to;
	   	if(son==father) continue;
	    if(dp[now][2]>=0)
	    	dp[son][2]=dp[now][2]+1;
	    if(son!=next[now]&&dp[now][0]>=0)
	    {
	    	dp[son][2]=max(dp[son][2],dp[now][0]+1);
	    }
	    else if(dp[now][1]>=0) 
	    {
	    	dp[son][2]=max(dp[son][2],dp[now][1]+1);
	    }
	    dfs_2(son,now);
   }
}
int main()
{
   int n,m,d;
   init();
   scanf("%d%d%d",&n,&m,&d);
   for(int i=1;i<=m;i++)
   {
   	 int x;
   	 scanf("%d",&x);
   	 po[x]=1;
   }
   for(int i=1;i<=n-1;i++)
   {
   	int a,b;
   	scanf("%d%d",&a,&b);
   	add(a,b);
   	add(b,a);
   }
   dfs_1(1,n+10);
   
   dfs_2(1,n+10);
   int ans=0;
   for(int i=1;i<=n;i++)
   {
   	 if(dp[i][0]<=d&&dp[i][2]<=d)
   		ans++;
   }
   printf("%d\n",ans);
   
   return 0;
}
