#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10005;
struct node
{
  int to;
  int next;
  int w;
}edge[N*2];
int top,head[N];
int dp[N][15];
int n,s,k;
void add(int from,int to,int w)
{
  edge[top].w=w;
  edge[top].to=to;
  edge[top].next=head[from];
  head[from]=top++;
}
void init()
{
  memset(head,-1,sizeof(head));
  memset(dp,0,sizeof(dp));
  top=0;
}
void dfs(int now,int father)
{
  for(int k=head[now];k!=-1;k=edge[k].next){
    if(edge[k].to==father) continue;
      dfs(edge[k].to,now);

    for(int j=10;j>=0;j--){
      dp[now][j]+=dp[edge[k].to][0]+2*edge[k].w;
     for(int ii=1;ii<=j;ii++)
      dp[now][j]=min(dp[now][j],dp[now][j-ii]+dp[edge[k].to][ii]+ii*edge[k].w);
   }
   }
}
int main()
{
  while(scanf("%d%d%d",&n,&s,&k)!=EOF){
    init();
    for(int i=1;i<=n-1;i++){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
      add(b,a,c);
    }
    dfs(s,-1);
    printf("%d\n",dp[s][k]);
  }
  return 0;
}
