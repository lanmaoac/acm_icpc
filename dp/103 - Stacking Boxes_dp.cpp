#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N= 55;
int n,w;
int dp[N];
int a[N][N];
int vis[N];
void init()
{
  memset(dp,0,sizeof(dp));
  memset(a,0,sizeof(a));
  memset(vis, 0, sizeof(vis));
  for(int i=0;i<n;i++){
    for(int j=0;j<w;j++)
      scanf("%d",&a[i][j]);
    sort(a[i],a[i]+w);
  }
}
bool judge(int c,int b)
{
  for(int i=0;i<w;i++)
    if(a[c][i]<=a[b][i]) return false;
  return true;
}
int find(int i)
{
   if(dp[i]) return dp[i];
   for(int j=0;j<n;j++)
    if(judge(j,i)){
        int a=find(j);
        if(a>dp[i]){
          dp[i]=a;
          vis[i]=j;
        }
    }
  return ++dp[i];
}
void gao()
{
      int Max=0,id,a;
      for(int i=0;i<n;i++)
      {
        a=find(i);
        if(a>Max)
        {
          Max=a;
          id=i;
        }
      }
      printf("%d\n", Max);
     for (int i = 1; i < Max; i++) {
     printf("%d ", id + 1);
     id = vis[id];
    }
    printf("%d\n", id + 1);
}
int main()
{
  while(scanf("%d%d",&n,&w)==2){
    init();
    gao();
  }
  return 0;
}
