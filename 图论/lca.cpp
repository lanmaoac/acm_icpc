#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int n,m,q,top,bn;
long long int dis[100010];
int ind,f[100010*2]={0},ati[100010*2]={0},b[3*100010]={0};
int dp[100010*2][30]={0};
long long int bit[100010]={0},fath[100010];
int star[2*100010];
int en[2*100010];
struct node
{
    int from;
    int to;
    int next;
    int w;
}edge[100010*2];
int head[100010];
void add(int from,int to,int cost)
{
    edge[top].from=from;
    edge[top].to=to;
    edge[top].next=head[from];
    edge[top].w=cost;
    head[from]=top++;
}
void dfs(int now,int father,int w)
{
    dis[now]=w;
    fath[now]=father;
    for(int k=head[now];k!=-1;k=edge[k].next)
    {
        int to=edge[k].to;
        if(to==father) continue;
        else dfs(to,now,w+edge[k].w);
    }
}
void dfs_2(int now,int father)
{
    int tmp=++ind;
    f[tmp]=now;
    b[++bn]=tmp;
    ati[now]=bn;
    star[now]=ind;
    for(int k=head[now];k!=-1;k=edge[k].next)
    {
        int to=edge[k].to;
        if(to==father) continue;
        dfs_2(to,now);
        b[++bn]=tmp;
    }
    en[now]=ind;
}
void RMQ_init(int n)
{
    for (int i=1; i<=n; i++)  dp[i][0]=b[i];
    int m=floor(log(n*1.0)/log(2.0));
    for (int j=1; j<=m; j++)
      for (int i=1; i<=n-(1<<j)+1; i++)
          dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
    int k=floor(log(r-l+1)/log(2.0));
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

int LCA(int a,int b)
{
    if (ati[a]>ati[b]) swap(a,b);
    return f[RMQ(ati[a],ati[b])];
}
void badd(int now,int a)
{
    while(now<=n)
    {
        bit[now]+=a;
        now+=now&(-now);
    }
}
int sum(int now)
{
    long long int ans=0;
    while(now>0)
    {
        ans+=bit[now];
        now-=(-now)&now;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    top=0;ind=0;bn=0;
    memset(head,-1,sizeof(head));
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs_2(1,0);
    RMQ_init(bn);
    scanf("%d",&q);
    fath[1]=0;
    dfs(1,1,0);
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            int father=LCA(b,c);
            printf("%lld\n",sum(star[b])+sum(star[c])-2*sum(star[father])+dis[b]+dis[c]-dis[father]*2);
        }
        else{
           b--;
           int x=edge[2*b].from;
           int y=edge[2*b].to;
           int cost=edge[2*b].w;
           if(fath[x]==y) swap(x,y);
           int p=c-cost;
           edge[2*b].w=edge[2*b+1].w=c;
           badd(star[y],p);
           badd(en[y]+1,-p);
        }
    }
    return 0;
}