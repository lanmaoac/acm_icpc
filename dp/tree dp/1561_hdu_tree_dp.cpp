#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 210;
vector<int>adj[N];
int n,m;
int dp[N][N];
int num[N];
int son[N];
void gao(int now)
{ 
  son[now]=1;
  int size=adj[now].size();
  for(int i=0;i<size;i++){
    gao(adj[now][i]);
    son[now]+=son[adj[now][i]];
    int tp= son[now] < m ? son[now]:m;
    for(int j=tp;j>=1;j--)
      for(int k=1;k<=j;k++)
        dp[now][j] = max(dp[now][j],dp[now][j-k]+dp[adj[now][i]][k]);
  }
  if(now!=0){
      for(int j=m;j>=1;j--)
           dp[now][j]=dp[now][j-1]+num[now];
  }
}
int main()
{
  
  while(scanf("%d%d",&n,&m)){
  if(n+m==0) break;  
  for(int i=0;i<=n;i++)
    adj[i].clear();
  memset(son,0,sizeof(son));
  memset(num,0,sizeof(num));
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      num[i]=b;
      adj[a].push_back(i);
  }
  gao(0);
  printf("%d\n",dp[0][m]);
  
  }
  return 0;
}
