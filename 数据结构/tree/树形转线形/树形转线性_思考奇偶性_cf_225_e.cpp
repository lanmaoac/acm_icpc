#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int head[200000*3],top=0,num=1;
struct node
{
 int to;
 int next;
}edge[200000*3];
int a[200000*3];
long long bit[3][200000*3];
long long s[4][200000*3];
void add(int from,int to)
{
  edge[top].to=to;
  edge[top].next=head[from];
  head[from]=top++;
}
void dfs(int now,int f,int z)
{
  s[0][now]=z;
  s[1][now]=++num;
  for(int k=head[now];k!=-1;k=edge[k].next)
      if(edge[k].to!=f)
        dfs(edge[k].to,now,1-z);
  s[2][now]=num;
}
void add_1(int x,int i,int v)
{
  while(i<=4000003){
    bit[x][i]+=v;
    i+=i & -i;
  }
}
long long sum(int x,int i)
{
   long long ans=0;
   while(i>0){
    ans+=bit[x][i];
    i-=i & -i;
   }
   return ans;
}
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   memset(head,-1,sizeof(head));
   for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
   for(int i=1;i<=n-1;i++){
    int ss,b;
    scanf("%d%d",&ss,&b);
    add(ss,b);
    add(b,ss);
   }
   dfs(1,-1,0);
   for(int i=1;i<=m;i++){
      int x; int u,va;
      scanf("%d",&x);
      if(x==1){
         scanf("%d%d",&u,&va);
         add_1(s[0][u],s[1][u],va);
         add_1(s[0][u],s[2][u]+1,-va);
         add_1((s[0][u]+1)%2,s[1][u],-va);
         add_1((s[0][u]+1)%2,s[2][u]+1,va);
      }
      else{
         scanf("%d",&u);
         printf("%I64d\n",a[u]+sum(s[0][u],s[1][u]));
      }
   }
   return 0;
}
